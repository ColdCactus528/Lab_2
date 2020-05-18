#include "Vector.cpp"

void testing_methods() {
		int size = 3;

		int sca_int = 2;
		int mas_0_int[size] = {1, 2, -4};
		int mas_1_int[size] = {6, -1, 1};
		int mas_answer_int_0[size] = {7, 1, -3};
		int mas_answer_int_1[size] = {2, 4, -8};
		int answer_int_0 = 4;
		int answe_int_1 = 0; 
		
		Vector<int> vec_0_int (mas_0_int, size);
		Vector<int> vec_1_int (mas_1_int, size);
		Vector<int>	vec_answer_int_0 (mas_answer_int_0, size);
		Vector<int>	vec_answer_int_1 (mas_answer_int_1, size);

		double sca_double = 1.1;
		double mas_0_double[size] = {1.1, 2.2, -4.4};
		double mas_1_double[size] = {6.3, -1.2, 1.1};
		double mas_answer_double_0[size] = {7.4, 1, -3.3};
		double mas_answer_double_1[size] = {1,21, 2.42, -4.84};
		double answer_double_0 = 5.04083;
		double answe_double_1 = -0.55; 

		Vector<double> vec_0_double (mas_0_double, size);
		Vector<double> vec_1_double (mas_1_double, size);
		Vector<double>	vec_answer_double_0 (mas_answer_double_0, size);
		Vector<double>	vec_answer_double_1 (mas_answer_double_1, size);


		Vector<int> vec_2_int = vec_0_int + vec_1_int;
		if (vec_2_int == vec_answer_int_0) {
			cout << "сложение векторов (целые) - SUCCESS" << endl; 
		}

		Vector<int> vec_3_int = vec_0_int * sca_int;
		if (vec_3_int == vec_answer_int_1) {
			cout << "умножение вектора на скаляр (целые) - SUCCESS" << endl; 
		}

		int check_int_0 = vec_0_int.rate_calculation();
		if (check_int_0 == answer_int_0){
			cout << "нахождение нормы (целые) - SUCCESS" << endl;
		}

		int scalar_int = vec_0_int.scalar_add(vec_1_int);
		if (scalar_int == answe_int_1) {
			cout << "скалярное умножение векторов (целые) - SUCCESS" << endl;
		}

		Vector<double> vec_2_double = vec_0_double + vec_1_double;
		if (vec_2_double == vec_answer_double_0) {
			cout << "сложение векторов (вещественные) - SUCCESS" << endl; 
		}

		Vector<double> vec_3_double = vec_0_double * sca_double;
		if (vec_3_double == vec_answer_double_1) {
			cout << "умножение вектора на скаляр (вещественные) - SUCCESS" << endl; 
		}

		double check_double_0 = vec_0_double.rate_calculation();
		if (check_double_0 == answer_double_0){
			cout << "нахождение нормы (вещественные) - SUCCESS" << endl;
		}

		double scalar_double = vec_0_double.scalar_add(vec_1_double);
		if (scalar_double == answe_double_1) {
			cout << "скалярное умножение векторов (вещественные) - SUCCESS" << endl;
		}

	}
