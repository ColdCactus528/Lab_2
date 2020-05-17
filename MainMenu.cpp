#include "Vector.cpp"
#include "VectorTest.cpp"

void main_menu() {
	cout << "Если вы хотите произвести операцию сложения векторов нажмите 3" << endl;
	cout << "Если вы хотите произвести опреацию умножения вектора на скаляр нажмите 4, после введите значение скаляра, после номер вектора (1 или 2)" << endl;
	cout << "Если вы хотите произвести опреацию нахождения нормы нажмите 5, после задайте номер вектора (1 или 2), у которого вы хотели бы найти норму" << endl;
	cout << "Если вы хотите произвести опреацию скалярного умножения векторов нажмите 6" << endl;
	cout << "Если хотите выйти нажмите 0";
}
void menu() {
  int size;
	int flag = 3;
	int flag_1;
	int x;
	double y;
	ArraySequence<int> arr_int_0;
	ArraySequence<int> arr_int_1;
	ArraySequence<double> arr_double_0;
	ArraySequence<double> arr_double_1;
	while (flag != 0 ) {
		cout << "Лабораторная номер 2, вариант 4 (Вектор для целых и вещественных чисел)" << endl;
		cout << "\n";
		cout << "Если хотите выйти нажмите 0, если хотите запустить тест нажмите 1, если хотите продолжить введите любое число кроме 0 и 1";
		cout << "\n";
		cin >> flag;
		cout << "\n";

		if (flag == 0) {
			cout << "bye";
			cout << "\n";
			break;
		}

		if (flag == 1) {
			testing_methods();
			cout << "\n";
		}

		cout << "Введите размерность векторов" << endl;
		cin >> size;
		cout << endl;
		cout << "Если вы хотите работать в целых числах нажмите 1, если в вещественных нажмите 2" << endl;
		cin >> flag;
		cout << endl;
		if (flag == 1) {
			cout << "Введите координаты первого вектора" << endl;
			for (int i = 0; i < size; ++i) {
				cin >> x;
				arr_int_0.Prepend(x);
			}

			cout << "Введите координаты второго вектора" << endl;
			for (int j = 0; j < size; ++j) {
				cin >> x;
				arr_int_1.Prepend(x);
			}

			Vector<int> vec_0 (arr_int_0);
			Vector<int> vec_1 (arr_int_1);
			cout << endl;
			while (flag != 0) {
				main_menu();
				cout << "\n";
				cin >> flag;
				cout << "\n";

				if (flag == 3) {
					Vector<int> vec = vec_0 + vec_1;
					vec.Show_V();
					cout << "\n";
					cout << "Введите 1 для продолжение работы" << endl;
					cin >> flag_1;
					if (flag_1 == 1) {
						cout << endl;
						cout << endl;
						cout << endl;
					}
				}

				if (flag == 4) {
					int sca;
					int a; 
					cout << "Скаляр равен = ";
					cin >> sca;
					cout << "\n";
					cout << "Номер верктора равен = ";
					cin >> a;
					cout << "\n";

					if (a == 1) {
						Vector<int> vec = vec_0 * sca;
						vec.Show_V();
						cout << "\n";
					}
					if (a == 2) {
						Vector<int> vec = vec_1 * sca;
						vec.Show_V();
						cout << "\n";
					}

					cout << "Введите 1 для продолжение работы" << endl;
					cin >> flag_1;
					if (flag_1 == 1) {
						cout << endl;
						cout << endl;
						cout << endl;
					}
				}

				if (flag == 5) {
					int a; 
					cout << "Номер верктора равен = ";
					cin >> a;
					cout << "\n";

					if (a == 1) {
						int norm = vec_0.rate_calculation();
						cout << "Норма вектора 1 равна = "<< norm << endl;
						cout << "\n";
					}
					if (a == 2) {
						int norm = vec_1.rate_calculation();
						cout << "Норма вектора 1 равна = " << norm << endl;
						cout << "\n";
					}
					
					cout << "Введите 1 для продолжение работы" << endl;
					cin >> flag_1;
					if (flag_1 == 1) {
						cout << endl;
						cout << endl;
						cout << endl;
					}
				}

				if (flag == 6) {
					int sca = vec_1.scalar_add(vec_0);
					cout << "Скалярное произведение векторов 1 и 2 = "<< sca << endl;
					cout << "\n";
					cout << "Введите 1 для продолжение работы" << endl;
					cin >> flag_1;
					if (flag_1 == 1) {
						cout << endl;
						cout << endl;
						cout << endl;
					}
				}
			}
		}

		if (flag == 2) {
			cout << "Введите координаты первого вектора" << endl;
			for (int i = 0; i < size; ++i) {
				cin >> y;
				arr_double_0.Prepend(y);
			}

			cout << "Введите координаты второго вектора" << endl;
			for (int j = 0; j < size; ++j) {
				cin >> y;
				arr_double_1.Prepend(y);
			}

			Vector<double> vec_0 (arr_double_0);
			Vector<double> vec_1 (arr_double_1);
			cout << endl;
			while (flag != 0) {
				main_menu();
				cout << "\n";
				cin >> flag;
				cout << "\n";

				if (flag == 3) {
					Vector<double> vec = vec_0 + vec_1;
					vec.Show_V();
					cout << "\n";
					cout << "Введите 1 для продолжение работы" << endl;
					cin >> flag_1;
					if (flag_1 == 1) {
						cout << endl;
						cout << endl;
						cout << endl;
					}
				}

				if (flag == 4) {
					double sca;
					int a; 
					cout << "Скаляр равен = ";
					cin >> sca;
					cout << "\n";
					cout << "Номер верктора равен = ";
					cin >> a;
					cout << "\n";

					if (a == 1) {
						Vector<double> vec = vec_0 * sca;
						vec.Show_V();
						cout << "\n";
					}
					if (a == 2) {
						Vector<double> vec = vec_1 * sca;
						vec.Show_V();
						cout << "\n";
					}

					cout << "Введите 1 для продолжение работы" << endl;
					cin >> flag_1;
					if (flag_1 == 1) {
						cout << endl;
						cout << endl;
						cout << endl;
					}
				}

				if (flag == 5) {
					int a; 
					cout << "Номер верктора равен = ";
					cin >> a;
					cout << "\n";

					if (a == 1) {
						double norm = vec_0.rate_calculation();
						cout << "Норма вектора 1 равна = "<< norm << endl;
						cout << "\n";
					}
					if (a == 2) {
						double norm = vec_1.rate_calculation();
						cout << "Норма вектора 1 равна = " << norm << endl;
						cout << "\n";
					}
					
					cout << "Введите 1 для продолжение работы" << endl;
					cin >> flag_1;
					if (flag_1 == 1) {
						cout << endl;
						cout << endl;
						cout << endl;
					}
				}

				if (flag == 6) {
					double sca = vec_1.scalar_add(vec_0);
					cout << "Скалярное произведение векторов 1 и 2 = "<< sca << endl;
					cout << "\n";
					cout << "Введите 1 для продолжение работы" << endl;
					cin >> flag_1;
					if (flag_1 == 1) {
						cout << endl;
						cout << endl;
						cout << endl;
					}
				}
			}
		}
	}
}  
