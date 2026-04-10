#include "stdafx.h"
#define  CYCLE  1000000                        

using namespace std;

int main2()
{
	setlocale(LC_ALL, "rus");

	cout << "\t\tЧисла Фибоначчи" << endl;
	int N;
	clock_t t3 = 0, t4 = 0;
	cout << "Введите количество чисел N: ";
	cin >> N;
	t3 = clock();
	int result = fibonachi(N);
	cout << "Результат функции чисел Фибоначчи: " << result;
	t4 = clock();
	std::cout << std::endl << "продолжительность (у.е):   " << (t4 - t3);
	std::cout << std::endl << "                  (сек):   "
		<< ((double)(t4 - t3)) / ((double)CLOCKS_PER_SEC);
	std::cout << std::endl;
	system("pause");

	return 0;
}
