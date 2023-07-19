#include "ST.h"

void main()
{
    setlocale(LC_CTYPE, "RUS");
    cout << "Введите строку: ";
    string str;
    cin >> str;
    skobki(str);
}
