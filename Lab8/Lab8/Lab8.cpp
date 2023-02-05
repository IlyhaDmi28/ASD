#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

struct Item
{
	unsigned short weight;
	unsigned short price;
	string name;
};

int main()
{
	setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	vector<Item> items;
    vector<short> Backpack;
	Item item;

	unsigned short N;

	cout << "Введите размер рюкзака: "; cin >> N;

	unsigned short choise = 1;

	while (choise == 1)
	{
		cout << "Введите название предмета: "; cin >> item.name;
		cout << "Ведите его цену: ";  cin >> item.price;
		cout << "Ведите его вес: "; cin >> item.weight;

		items.push_back(item);

		cout << "1 - Добавить предме, 2 - Вывести предметы, положеннные в рюкзак: "; cin >> choise;
	}


    system("cls");

    for (short i = 0; i < items.size(); i++)
    {
        cout << items[i].name << ", вес: " << items[i].weight << ", цена: " << items[i].price << endl;
    }

	unsigned short** Cost = new unsigned short* [items.size() + 1];
	for (short i = 0; i <= items.size(); i++)
	{
		Cost[i] = new unsigned short[N + 1];		
	}

    for (int i = 0; i <= items.size(); i++)
    {
        //проходим по всем рюкзакам
        for (int j = 0; j <= N; j++)
        {
            //попадаем в ячейку пустышку
            if (i == 0 || j == 0)
            {
                Cost[i][j] = 0;
            }
            else
            {


                //если вес текущей вещи больше размера рюкзака
                //казалось бы откуда значение возьмется для первой вещи 
                //при таком условии. А оно возьмется из ряда пустышки
                if (items[i - 1].weight > j)
                {
                    Cost[i][j] = Cost[i - 1][j];
                }
                else
                {
                    //здесь по формуле. значение над текущей ячейкой
                    unsigned short prev = Cost[i - 1][j];
                    //значение по вертикали: ряд вверх
                    //и по горизонтали: вес рюкзака - вес текущей вещи
                    unsigned short byformula = items[i - 1].price + Cost[i - 1][ j - items[i - 1].weight];


                    if (prev > byformula)  Cost[i][j] = prev;
                    else
                    {
                        Cost[i][j] = byformula;
                        
                        //if(Cost[i][j] != Cost[i][j - j]) Backpack.push_back(items[i - 1]);

                    }

                    //ChecKBackpack(N);                 
                }
            }
        }
    }

    short sum = 0;
    for (short i = items.size(), j = N; i > 0;  i-- )
    {
        if (i == 1)
        {
            if (sum + items[0].weight > N) break;
        }

        if (Cost[i - 1][j] != Cost[i][j])
        {
            Backpack.push_back(i);
            j -= i;
            sum += items[i - 1].weight;
        }

        
    }

    cout << endl;
    for (short i = 0; i < items.size() + 1; i++)
    {
        for (short j = 0; j < N; j++)
        {
            cout << Cost[i][j] << '\t';
        }
        cout << endl;
    }

    cout << endl << "Стоимость предметов в рюкзаке: " << Cost[items.size()][N] << endl;
    cout << "Предметы в рюкзаке: " << endl;
    for (short i = 0; i < Backpack.size(); i++)
    {
        cout << items[Backpack[i] - 1].name << ", вес: " << items[Backpack[i] - 1].weight << ", цена: " << items[Backpack[i] - 1].price <<  endl;
    }
}



