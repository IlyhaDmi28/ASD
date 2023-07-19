#pragma once
#include <iostream>

using namespace std;

void shop()
{
    int N;
    cout << "Введите количестов товаров: ";
    cin >> N;
    int* SELL = new int[N];
    cout << "Цены товаров: ";
    for (int i = 0; i < N; i++)
    {
        SELL[i] = (rand() % 100) + 1;
        cout << SELL[i] << ' ';
    }

    int buff;

    for (int j = 0; j < N; j += 2)
    {
        for (int i = 1; i < N; i += 2)
        {
            if (SELL[j] < SELL[i])
            {
                buff = SELL[j];
                SELL[j] = SELL[i];
                SELL[i] = buff;
            }
        }
    }

    cout << "\nПорядок побивания товаров: ";
    for (int i = 0; i < N; i++)
    {
        cout << SELL[i] << ' ';
    }

    cout << "\nСумма чека: ";
    int sum = 0;
    for (int i = 0; i < N; i += 2)
    {
        sum += SELL[i];
    }
    cout << sum << endl;
}

void pizer()
{
    int N;
    cout << "Введите число участников: ";
    cin >> N;
    int* PRIZ = new int[N];
    for (int i = 0; i < N; i++)
    {
        PRIZ[i] = (rand() % 7) + 1;
        cout << PRIZ[i] << ' ';
    }
    int max[3];
    max[0] = PRIZ[0];
    for (int i = 1; i < N; i++)
    {
        if (PRIZ[i] > max[0]) {
            max[0] = PRIZ[i];
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (PRIZ[i] > max[0]) {
            max[0] = PRIZ[i];
        }
    }
    max[1] = max[0];
    max[2] = max[0];

    for(int j = 1; j < 3; )
    {
        max[j]--;
        for (int i = 0; i < N; i++)
        {
            if (max[j] == PRIZ[i])
            {
                j++;
                if (j < 3) max[j] = max[j - 1];
                break;
            }
        }
    }
    int numPriz = 0;
    for (int i = 0; i < N; i++)
    {
        if (PRIZ[i] == max[0] || PRIZ[i] == max[1] || PRIZ[i] == max[2]) numPriz++;
    }
    cout << "\nКоличестов призёров: " << numPriz;
}