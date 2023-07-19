#include <iostream>
#include <ctime>
#include "func.h"
using namespace std;

void shop();
void pizer();

void main()
{
    setlocale(LC_CTYPE, "RUS");

    srand(time(0));
    shop();
    cout << endl;
    pizer();
}
