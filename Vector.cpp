#include "Sequence.cpp"
#include <math.h>
#include <cstdlib>

template <class T> class Vector {
public:
	struct complex_number{
		T real;
		T comp;

	complex_number& operator=(complex_number& number)  {
		real = number.real;
		comp = number.comp;

		return *this;
	}

	complex_number& operator+(complex_number& number) {
		complex_number* new_number = new complex_number;
		new_number->real = real + number.real;
		new_number->comp = comp + number.comp;

		return new_number;
	}

	complex_number& operator*(T& number) {
		complex_number* new_number = new complex_number;
		new_number->real = real*number;
		new_number->comp = comp*number;

		return new_number;
	}

	complex_number& operator*(complex_number& number) {
		complex_number* new_number = new complex_number;
		new_number->real = real*number.real - comp*number.comp;
		new_number->comp = real*number.comp + comp*number.real;

		return new_number;
	}

	};

	Vector(T* item, int size):data(item, size) {
		
	}

	Vector() {

	}

	Vector(ArraySequence<T>& Array):data(Array) {

	}

	void Show_V() {
		for (int i = 0; i < data.GetLength(); ++i) {
			cout << "coordinate " << i+1 << " = " <<  data.Get(i) << endl;
		}
	}

	Vector<T>& operator=(Vector<T>& vec) {
		for (int i = 0; i < vec.data.GetLength(); ++i) {
			data.Prepend(vec.data.Get(i));
		}
	}

	Vector<T>& operator+(Vector<T>& vec_1) {
		if (vec_1.data.GetLength() != data.GetLength()) {
			cout << "Error: vectors have different dimensions" << endl;
			throw logic_error("logic error");
		}

		Vector<T>* new_v = new Vector<T>;
		for (int i = 0; i < data.GetLength(); ++i) {
			new_v->data.Prepend(data.Get(i) + vec_1.data.Get(i));
		}

		return *new_v;
	}

	Vector<T>& operator*(T& scalar) {
		Vector<T>* new_v = new Vector<T>;
		for (int i = 0; i < data.GetLength(); ++i) {
			new_v->data.Prepend(data.Get(i) * scalar);
		}

		return *new_v;
	}

	bool operator==(Vector<T>& vec_1) {
		if (data.GetLength() != vec_1.data.GetLength()){
			cout << "Error: vectors have different dimensions" << endl;
			throw logic_error("logic error");
		}
		for (int i = 0; i < data.GetLength(); ++i) {
			if (data.Get(i) != vec_1.data.Get(i)) {
				return false;
			}
		}

		return true;
	}

	T rate_calculation(){
		T* rate = new T;
		*rate = 0;
		for (int i = 0; i < data.GetLength(); ++i) {
			*rate = *rate + data.Get(i)*data.Get(i);
		}
		return sqrt(*rate);
	}

	T scalar_add(Vector<T>& vec) {
		T* scalar = new T;
		*scalar = 0;
		for (int i = 0; i < data.GetLength(); ++i) {
			*scalar = *scalar + vec.data.Get(i)*data.Get(i);
		}

		return *scalar;
	}
private:
	ArraySequence<T> data;
};
