#include <iostream>
#include <time.h>
#include <tchar.h>
#include "sort.h"
using namespace std;

void main()
{
    setlocale(LC_ALL, "rus");
    int N;
    clock_t stime, etime;
    double bdelay, idelay, sdelay, qdelay;
    cout << "Введите количество значений N: ";
    cin >> N;
    int *A = new int[N];
    int *B = new int[N];
    int *C = new int[N];
    int *D = new int[N];
    int *E = new int[N];
    cout << "Массив A: ";
    for (int i = 0; i < N; i++)
    {
        A[i] = rand() % 1000;
        B[i] = A[i];
        C[i] = A[i];
        D[i] = A[i];
        E[i] = A[i];
        cout << A[i] << ' ';
    }
    stime = clock();
    buble(B, N);
    etime = clock();
    bdelay = ((double)etime - (double)stime) / (double)CLOCKS_PER_SEC;
    cout << "\n\nМассив, отсортированный пузырьковской сортировкой: ";
    for (int i = 0; i < N; i++)
    {
        cout << B[i] << ' ';
    }

    stime = clock();
    insert(C, N);
    etime = clock();
    idelay = ((double)etime - (double)stime) / (double)CLOCKS_PER_SEC;
    cout << "\nМассив, отсортированный методом вставки: ";
    for (int i = 0; i < N; i++)
    {
        cout << C[i] << ' ';
    }
    
    stime = clock();
    select(D, N);
    etime = clock();
    sdelay = ((double)etime - (double)stime) / (double)CLOCKS_PER_SEC;
    cout << "\nМассив, отсортированный методом выбора: ";
    for (int i = 0; i < N; i++)
    {
        cout << D[i] << ' ';
    }

    stime = clock();
    qsortRecursive(E, N);
    etime = clock();
    qdelay = ((double)etime - (double)stime) / (double)CLOCKS_PER_SEC;
    cout << "\nМассив, отсортированный быcтрой сортировкой : ";
    for (int i = 0; i < N; i++)
    {
        cout << E[i] << ' ';
    }
    cout << "\n\nВремя выполнения:\n";
    cout << "Пузырьковская сортировка: " << bdelay << endl;
    cout << "Метод вставки: " << idelay << endl;
    cout << "Метод выбора: " << sdelay << endl;
    cout << "Быстрая сортировка: " << qdelay << endl;
}