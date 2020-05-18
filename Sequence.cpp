#include "DynamicArr.cpp"
#include "LinkedList.cpp"

template <class T> class Sequence {
public:

	virtual T GetFirst() = 0;

	virtual T GetLast() = 0;

	virtual T Get(int index) = 0;

	virtual Sequence<T>* GetSubSequence(int startIndex, int endIndex) = 0;

	virtual int GetLength() = 0;

	virtual void Append(T item) = 0;

	virtual void Prepend(T item) = 0;

	virtual void InsertAt(T item, int index) = 0;

	virtual Sequence<T>* Concat(Sequence<T>* list) = 0;
	
};

template <class T> class ArraySequence: public Sequence<T> {
public:
	ArraySequence(T* items, int count):data(items, count) {

	}

	ArraySequence(): data(0){
		// data(100);
	}

	ArraySequence(int count): data(count) {

	}

	ArraySequence(const DynamicArray<T>& dynArray):data(dynArray) {
		// data(dynArray);
	}

	T GetFirst() override {
		return data.Get(0);
	}

	T GetLast() override {
		return data.Get(data.GetSize() - 1);
	}

	T Get(int index) override {
		return data.Get(index);
	}

	int GetLength() override {
		// cout << data.GetSize() << endl;
		return data.GetSize();
	}

	void Append(T item) override {
		int large = data.GetSize();
		DynamicArray<T> new_arr(large + 1);
		new_arr.Set(0, item);
		for (int i = 0; i < large; ++i) {
			new_arr.Set(i+1, data.Get(i));
		}
		data = new_arr;
	}

	void InsertAt(T item, int index) override {
		int large = data.GetSize() + 1;
		DynamicArray<T> new_arr(large);
		int j = 0;
		for (int i = 0; i < large; ++i) {
			if (i == index) {
				new_arr.Set(i, item);
				continue;
			}
			new_arr.Set(i, data.Get(j));
			++j;
		}
		data = new_arr;
	}

	void Prepend(T item) override {
		int new_length = data.GetSize() + 1;
		data.Resize(new_length);
		data.Set(new_length - 1, item);
	}

	Sequence<T>* GetSubSequence(int startIndex, int endIndex) {
		if ((endIndex < 0) || (startIndex < 0) || (startIndex >= GetLength()) || (endIndex >= GetLength()) || (startIndex > endIndex)) {
			cout << "Error: IdexOutOfRange" << endl;
			throw logic_error("logic error");
		}
		int large = endIndex - startIndex + 1;
		ArraySequence<T>* new_arr = new ArraySequence<T>;
		int z = 0;
		for (int i = 0; i < GetLength(); ++i) {
			if ((i >= startIndex) && (i <= endIndex)) {
				new_arr->InsertAt(Get(i), z);
				++z;
			} 
		}
		return new_arr;
	}

	Sequence<T>* Concat(Sequence<T>* list) {
		ArraySequence<T>* new_mas =  new ArraySequence<T> ;
		for (int i = 0; i < GetLength(); i++) {
			new_mas->InsertAt(Get(i), i);
		}
		int k = 0;
		for (int j = GetLength(); j < GetLength() + list->GetLength(); ++j) {
			new_mas->InsertAt(list->Get(k), j);
			++k;
		}

		return new_mas;
	}

	~ArraySequence() {

	}
private:
	DynamicArray<T> data;
};

template <class T> class LinkedListSequence: public Sequence<T> {
public:
	LinkedListSequence(T* item, int count):data(item, count) {
	}

	LinkedListSequence():data() {
	}

	LinkedListSequence(const LinkedList<T>& list):data(list) {
	}

	T Get(int index) {
		data.Get(index);
	}

	T GetFirst() {
		data.GetFirst();
	}

	T GetLast() {
		data.GetLast();
	}

	int GetLength() {
		data.GetLength();
	}

	void Append(T item) {
		data.Append(item);
	}

	void Prepend(T item) {
		data.Prepend(item);
	}

	void InsertAt(T item, int index) {
		data.InsertAt(item, index);
	}

	Sequence<T>* GetSubSequence(int startIndex, int endIndex) {
		if (startIndex > endIndex) {
			cout << "Error: startIndex > endIndex" << endl;
			throw logic_error("logic error");
		}
		if ((startIndex < 0) || (endIndex < 0)){
			cout << "Error: IdexOutOfRange" << endl;
			throw logic_error("logic error");
		}
		int large = GetLength();
		if ((endIndex >= large) || (startIndex >= large)) {
			cout << "Error: IdexOutOfRange" << endl;
			throw logic_error("logic error");		
		}

		LinkedListSequence<T>* new_list = new LinkedListSequence<T>;
		for (int i = startIndex; i <= endIndex; ++i){
			new_list->Prepend(Get(i));
		}

		return new_list;
	}
	Sequence<T>* Concat(Sequence<T>* list) {
		LinkedListSequence<T>* new_list = new LinkedListSequence<T>;
		for (int i = 0; i < GetLength(); ++i) {
			new_list->Prepend(Get(i));
		}
		int k = 0;
		for (int j = GetLength(); j < GetLength() + list->GetLength(); ++j){
			new_list->Prepend(list->Get(k));
			++k;
		}
		return new_list; 
	}
	~LinkedListSequence() {

	}

private:
	LinkedList<T> data;
};
