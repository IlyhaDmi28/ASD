#include <iostream>
using namespace std;

int binnarySearch(int leftb, int value, int rightb, bool showSteps = false);

int main()
{
    setlocale(LC_CTYPE, "RUS");
    int N, X;

    cout << "Ввелите правую границу: "; cin >> N;

    cout << "Введите число, которое надо найти: "; cin >> X;
    
    cout << "Количество шагов = " << binnarySearch(1, X, N, true) << endl;
}

int binnarySearch(int leftb, int value, int rightb, bool showSteps) {
    int count = 0;
    int result = 0;

    while (result != value)
    {
        result = ((rightb - leftb) / 2) + leftb;
        if (showSteps) cout << result << " - ";

        if (result < value)
        {
            leftb = result;
            cout << "Мало\n";
        }
        else if (result > value)
        {
            rightb = result;
            cout << "Много\n";
        }
        else cout << "Угадал\n";

        count++;
    }

    return count;
}