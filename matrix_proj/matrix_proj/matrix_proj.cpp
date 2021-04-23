#include "pch.h"
#include <iostream>
#include <locale>
#include <iomanip>
#include "matrix.h"

using namespace std;
using namespace math;

int main()
{
	setlocale(LC_CTYPE, "RUS");

	//matrix G = { {1.3333333, 2.33333333}, {5.232323232, 5.222} };
	//cout << G.at(0, 0) << endl;
	//cout << G << endl;

	/* Тесты оператора листа инициализации */
	//matrix K1 = { {} };
	//matrix K2 = { };
	//matrix K3 = { {1}, {} };
	//matrix K4 = { {}, {}, {} };

	/* Тест оператора присваивание */
	/*matrix L1 = { {3}, {4}, {2} };
	matrix L2 = { {3}, {4}, {2} };
	L1 = move(L1);
	cout << L1 << endl;*/

	/* Конструктор матрицы (row, col)*/
	//matrix M(1, 0);

	///* Проверка оператора присваивания */
	//matrix G = { {1.33333355553, 2.33333333}, {5.232323232, 5.222} };
	//matrix H;
	//cout << G << endl;

	///* Тесты листа инициализации */
	//initializer_list<initializer_list<double>> v = { {} };
	//cout << "size: " << v.size() << endl;
	//cout << "size begin: " << v.begin()->size() << endl;
	//matrix m(3, 5);
	////m = { {} };
	//cout << m << endl;
	//m = v;

	//initializer_list<initializer_list<double>> v = { {1, 2}, {2, 5} };
	//matrix m = v;
	//cout << "m: " << endl << m << endl;
	//matrix m2(2, 2);
	//m2 = v;
	//cout << "m2_v1: " << endl << m2 << endl;
	//m2 = m; 
	//cout << "m2_v2: " << endl << m2 << endl;
	//matrix m3(9, 9);
	//m3 = v;
}