#include <iostream>
#include <string>
using namespace std;

template <class T> class LinkedList {
public:
	struct node {
		T data;
		node* next;
	};

	LinkedList() {
		head = NULL;
		tail = NULL;
	}

	LinkedList(T* items, int count) {
		head = NULL;
		tail = NULL;

		for (int i = 0; i < count; ++i) {
			node* temp = new node;
			temp->data = items[i];
			temp->next = NULL;

			if (head == NULL) {
				head = temp;
				tail = temp;
				temp = NULL;
			}
			else {
				tail->next = temp;
				tail = temp;
			}
		}
	}

	LinkedList(const LinkedList<T> & list) {
		head = NULL;
		tail = NULL;

		node* temp = list.head;
		while (temp != NULL) {
			node* new_temp = new node;
			new_temp->data = temp->data;
			new_temp->next = NULL;

			if (head == NULL) {
				head = new_temp;
				tail = new_temp;
				new_temp = NULL;
			}
			else {
				tail->next = new_temp;
				tail = new_temp;
			}

			temp = temp->next;
		}
	}

	T GetFirst() const {
		if (head == NULL) {
			cout << "Error: IdexOutOfRange" << endl;
			throw logic_error("logic error");
		}
		return head->data;
	}

	T GetLast() const {
		if (head == NULL) {
			cout << "Error: IdexOutOfRange" << endl;
			throw logic_error("logic error");
		}
		return tail->data;
	}

	T Get(int index) {
		if (head == NULL) {
			cout << "Error: IdexOutOfRange" << endl;
			throw logic_error("logic error");
		}

		node* ptr = head;
		int z = 0;
		while (ptr != NULL) {
			ptr = ptr->next;
			++z;
		}
		if ((index < 0) || (index >= z)) {
			cout << "Error: IdexOutOfRange" << endl;
			throw logic_error("logic error");		
		}

		if (index == 0) {
			return head->data;
		}
		else {
			node* temp = head->next;
			for (int i = 1; i < index; ++i) {
				temp = temp->next;
			}
			return temp->data;
		}
	}

	int GetLength() const {
		if (head == NULL)
			return 0;

		node* temp = head;
		int i = 0;
		while (temp != NULL) {
			temp = temp->next;
			++i;
		}
		return i;
	}

	void Append(T item) {
		node* temp = new node;
		temp->data = item;

		if (head == NULL) {
			temp->next = NULL;
			head = temp;
			tail = temp;
			temp = NULL;
		} 
		else {
			node* ptr = head;
			temp->next = ptr;
			head = temp;
		}
	}

	void Prepend(T item) {
		node* temp = new node;
		temp->data = item;
		temp->next = NULL;

		if (head == NULL) {
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
	}

	void InsertAt(T item, int index) {
		if (index < 0) {
			cout << "Error: IdexOutOfRange" << endl;
			throw logic_error("logic error");
		}
		if (index == 0) {
			node* temp = new node;
			temp->data = item;

			if (head == NULL) {
				temp->next = NULL;
				head = temp;
				tail = temp;
				temp = NULL;
			} 
			else {
				node* ptr = head;
				temp->next = ptr;
				head = temp;
			}
		}
		else {
			node* temp = head;
			int check = 0;
			int i = 0;
			while (temp !=NULL) {
				if (i == index-1) {
					node* new_temp = new node;
					new_temp->data = item;
					node* ptr = temp->next;
					temp->next = new_temp;
					new_temp->next = ptr;
					check = 1;
					break;  
				}
				temp = temp->next;
				++i;
			}

			if (check == 0 ) {
				cout << "Error: IdexOutOfRange" << endl;
				throw logic_error("logic error");
			} 
		} 
	}

	LinkedList<T>* GetSubList(int startIndex, int endIndex) {
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

		LinkedList<T>* new_list = new LinkedList<T>;
		node* temp = head;
		int i = 0;
		for (;temp != NULL; temp = temp->next, ++i) {
			if ((i >= startIndex) && (i <= endIndex)) {
				new_list->Prepend(temp->data);
			}
		}
		return new_list;
	}

	LinkedList<T>* Concat(LinkedList<T>* list) {
		LinkedList<T>* new_list = new LinkedList;
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

	~LinkedList() {
		node* temp = head;
		node* next_temp;
		while (temp !=NULL){
			next_temp = temp->next;
			delete temp;
			temp = next_temp;
		}
	}
private:

	node* head, *tail;
};
