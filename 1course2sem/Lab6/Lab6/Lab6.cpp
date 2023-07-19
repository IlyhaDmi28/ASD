#include "Hash.h"
    
void main()
{

    HashTab Tab[SIZE];
    setlocale(LC_ALL, "RUS");
    unsigned short choise;
    do
    {
        cout << "1. Добавить элемента" << endl;
        cout << "2. Найти элемент" << endl;
        cout << "3. Удалить элемент" << endl;
        cout << "4. Просмотреть всю таблицу" << endl;
        cout << "0. Выход" << endl << endl;
        
        cout << "Выберите пункт: ";
        cin >> choise;
        switch (choise)
        {
        case 1: { add(Tab); cout << endl; break; }
        case 2: { find(Tab); cout << endl; break; }
        case 3: { del(Tab); cout << endl; break; }
        case 4: { out(Tab); cout << endl; break; }
        default: break;
        }
    } while (choise);
}
