#include <iostream>
#include <time.h>

using namespace std;

int FibonachyC(int N);
int FibonachyR(int N);

void main()
{
	setlocale(LC_ALL, "Rus");
	int N;

	clock_t nowTime, deltaTime;

	double cycleTime, recursionTime;

	cout << "Ввелите N: ";
	cin >> N;

	nowTime = clock();
	cout << "Число Фибоначи через цикл: ";
	for (int i = 0; i < N; i++)
	{
		cout << FibonachyC(i) << ' ';
	}
	deltaTime = clock();

	cycleTime = ((double)deltaTime - (double)nowTime) / (double)CLOCKS_PER_SEC;

	nowTime = clock();
	cout << "\nЧисло Фибоначи через рекурсию: ";
	for (int i = 0; i < N; i++)
	{
		cout << FibonachyR(i) << ' ';
	}
	deltaTime = clock();

	recursionTime = ((double)deltaTime - (double)nowTime) / (double)CLOCKS_PER_SEC;

	cout << "\nВремя выполнения программы через цикл: " << cycleTime << endl;
	cout << "Время выполнения программы через рекурсию: " << recursionTime << endl;

	cout << "Разность времени: " << abs(cycleTime - recursionTime) << endl;
}

int FibonachyC(int N) {
	int F1 = 0, F2 = 1, FN;

	if (N == 0 || N == 1) return N;

	for (int i = 0; i < N - 1; i++)
	{
		FN = F1 + F2;

		F1 = F2;

		F2 = FN;

	}
	
	return FN;
}

int FibonachyR(int N) {
	if (N == 0 || N == 1) return N;

	return FibonachyR(N - 1) + FibonachyR(N - 2);
}