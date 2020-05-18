#include <iostream>
#include <string>
using namespace std;

template <class T> class DynamicArray {
public:
	DynamicArray(int size) {
		this->size = size;
		ptr_mas = new T [size];
	}

	T &operator[](int index) {
		return *(ptr_mas + index);
	}

	DynamicArray<T> &operator=(DynamicArray<T> rhs) {
		if (size != rhs.size) {
			Resize(rhs.size);
		}
		for (int i = 0; i < rhs.size; ++i) {
			ptr_mas[i] = rhs.ptr_mas[i];
		}

		return *this;

	}

	DynamicArray(T* items, int count) {
		size = count;
		ptr_mas = new T [count];
		for (int i = 0; i < count; ++i)
			ptr_mas[i] = items[i];
	}

	DynamicArray(const DynamicArray<T>  &dyn_arr) {
		size = dyn_arr.GetSize();
		ptr_mas = new T [size];
		for (int i = 0; i < size; ++i)
			ptr_mas[i] = dyn_arr.Get(i); 
	}

	const T &Get(int index) const {
		if ((index < 0) || (index >= size)) {
			cout << "Error: IdexOutOfRange" << endl;
			throw logic_error("logic error");
		}
		return ptr_mas[index];
	}

	int GetSize() const{
		return size;
	}

	void Set(int index, T value) {
		ptr_mas[index] = value;
	}

	void Resize(int newSize){
		if (size < newSize) {
			T* ptr_new_mas = new T [newSize];
			for (int i = 0; i < size; ++i) 
				ptr_new_mas[i] = ptr_mas[i];

			delete ptr_mas;
			ptr_mas = ptr_new_mas;
			size = newSize;
		}

		if (size > newSize) {
			T* ptr_new_mas = new T [newSize];
			for (int i = 0; i < newSize; i++)
				ptr_new_mas[i] = ptr_mas[i];

			delete ptr_mas;
			ptr_mas = ptr_new_mas;
			size = newSize;
		}
	}

	~DynamicArray() {
		delete ptr_mas;
	}
private:
	int size;
	T* ptr_mas;
};	
