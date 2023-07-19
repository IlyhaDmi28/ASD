#pragma once

void qsortRecursive(int* mas, int size) {
    int i = 0;
    int j = size - 1;

    int mid = mas[size / 2];

    do {

        while (mas[i] < mid) {
            i++;
        }

        while (mas[j] > mid) {
            j--;
        }

        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    if (j > 0) {
        qsortRecursive(mas, j + 1);
    }
    if (i < size) {

        qsortRecursive(&mas[i], size - i);
    }
}

void buble(int *B, int N)
{
    int temp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (B[j] > B[j + 1]) {       
                 temp = B[j];
                 B[j] = B[j + 1];
                 B[j + 1] = temp;
            }
        }
    }
}

void insert(int* C, int N)
{
    int item, temp;
    for (int i = 1; i < N; i++)
    {
        temp = C[i];
        item = i - 1;
        while (item >= 0 && C[item] > temp)
        {
            C[item + 1] = C[item];
            C[item] = temp;
            item--;
        }
    }
}

    void select(int *D, int N)
    {
        int min = 0, temp;
        for (int i = 0; i < N; i++)
        {
            min = i;
       
            for (int j = i + 1; j < N; j++)
                min = (D[j] < D[min]) ? j : min;
       
            if (i != min)
            {
                temp = D[i];
                D[i] = D[min];
                D[min] = temp;
            }
        }
    }
