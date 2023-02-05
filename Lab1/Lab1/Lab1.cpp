#include <iostream>
using namespace std;

void HanoiTower(int i, int k, int n, int* count) {

	if (n == 1) {

		cout << (*count)++ << ") Перместить диск 1 с стержня " << i << " на стержень " << k << ".\n";

	}
	else {

		int tmp = n;

		HanoiTower(i, tmp, n - 1, count);

		cout << (*count)++ << ") Переместить диск " << n << " с стержня " << i << " на стержень " << k << ".\n";

		HanoiTower(tmp, k, n - 1, count);
	}
}

int main() {
	setlocale(LC_ALL, "RUS");
	int count = 1;
	int pinc, diskc;

	cout << "Введите количество стержней: "; cin >> pinc;
	cout << "Введите количество дисков: "; cin >> diskc;
	if (pinc <= 0 || diskc <= 0) { cout << "Неверные данные!!!"; return 0; };
	HanoiTower(1, pinc, diskc, &count);

	return 0;
}