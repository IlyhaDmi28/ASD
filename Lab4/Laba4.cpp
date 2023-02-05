#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    float D[6][6] = {
              //1 2 3 4 5 6
        /*1*/ {0, 28, 21, 59, 12, 27},
        /*2*/ {7, 0, 24, INFINITY, 21, 9},
        /*3*/ {9, 32, 0, 13, 11, INFINITY},
        /*4*/ {8, INFINITY, 5, 0, 16, INFINITY},
        /*5*/ {14, 13, 15, 10, 0, 22},
        /*6*/ {15, 18, INFINITY, INFINITY, 6, 0}
    };

    int S[6][6] = {
        {0, 2, 3, 4, 5, 6},
        {1, 0, 3, 4, 5, 6},
        {1, 2, 0, 4, 5, 6},
        {1, 2, 3, 0, 5, 6},
        {1, 2, 3, 4, 0, 6},
        {1, 2, 3, 4, 5, 0},
    };

    for (int m = 0; m < 6; m++)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (D[i][m] + D[m][j] < D[i][j] && (i != j && i != m && j != m)) {
                    D[i][j] = D[i][m] + D[m][j];
                    S[i][j] = m + 1;
                }
            }
        }
    }

    int i, j;

    cout << "Введите начальную вершину: "; cin >> i;
    if (i > 6 || i < 1) { cout << "Такой вершины нет!!!"; return 0; }

    cout << "Введите конечную вершину: "; cin >> j;
    if (j > 6 || j < 1) { cout << "Такой вершины нет!!!"; return 0; }

    cout << "Растояние: " << D[i - 1][j - 1] << ", Промежутки: " << i << "->" << S[i - 1][j - 1];
    if(S[i - 1][j - 1] != j) cout << "->" << j;
    
    cout << endl;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << D[i][j] << '\t';
        }
        cout << endl;
    }

    cout << endl;


    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << S[i][j] << '\t';
        }
        cout << endl;
    }
}
