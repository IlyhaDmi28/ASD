#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));

    unsigned short N;
    cout << "Введите длину последовательности: "; cin >> N;

    short* Sequence = new short[N];
    short* Counts = new short[N];
    short* P = new short[N];

    cout << "Последовательность: ";
    for (short i = 0; i < N; i++)
    {
        cin >> Sequence[i];
        //Sequence[i] = 1 + rand() % 100;
        //cout << Sequence[i] << ' ';
        Counts[i] = 1;
        P[i] = -1;
    }

    for (short i = 1; i < N; i++)
    {
        
        for (short j = 0; j < i; j++)
        { 
            if (Sequence[i] > Sequence[j] && Counts[i] <= Counts[j])
            {
                Counts[i] = Counts[j] + 1;
                P[i] = j;
            }
        }
    }

    cout << endl;

    short max = Counts[0], pos = 0;
    for (short i = 0; i < N; i++)
    {
        if (max <= Counts[i])
        {
            max = Counts[i];
            pos = i;
        }
    }

    cout << endl << endl;

    vector<int> path;
    while (pos != -1) {
        path.push_back(pos);
        pos = P[pos];
    }
    reverse(path.begin(), path.end());
    for (size_t i = 0; i < N; i++)
    {
        cout << Sequence[i] << "\t(" << Counts[i] << ", " << P[i] << ")" << endl;
    }

    cout << endl;
    for (int i = 0; i < (int)path.size(); i++) cout << Sequence[path[i]] << ' ';

    cout << endl << endl << "Длина возварстающей подпоследовательности: " << max << endl;

    max = Counts[0]; pos = 0;
    for (short i = 0; i < N; i++)
    {
        if (max < Counts[i])
        {
            max = Counts[i];
            pos = i;
        }
    }

    cout << endl << endl;

    path.clear();
    while (pos != -1) {
        path.push_back(pos);
        pos = P[pos];
    }
    reverse(path.begin(), path.end());
    for (size_t i = 0; i < N; i++)
    {
        cout << Sequence[i] << "\t(" << Counts[i] << ", " << P[i] << ")" << endl;
    }

    cout << endl;
    for (int i = 0; i < (int)path.size(); i++) cout << Sequence[path[i]] << ' ';

    cout << endl << endl << "Длина возварстающей подпоследовательности: " << max + 1 << endl;
}