#include <iostream>
using namespace std;

int main()
{
    float D[6][6] = {
             //1 2 3 4 5 6
        /*1*/ {0, 28, 21, 59, 12, 27},
        /*2*/ {7, 0, 24, INFINITY, 21, 9},
        /*3*/ {9, 32, 0, 13, 11, INFINITY},
        /*4*/ {8, INFINITY, 5, 0, 16, INFINITY},
        /*5*/ {14, 13, 15, 10, 0, 22},
        /*6*/ {15, 18, INFINITY, INFINITY, 6, 15}
    };
    int S[6][6] = {
        {1, 2, 3, 4, 5, 6},
        {1, 2, 3, 4, 5, 6},
        {1, 2, 3, 4, 5, 6},
        {1, 2, 3, 4, 5, 6},
        {1, 2, 3, 4, 5, 6},
        {1, 2, 3, 4, 5, 6},
    };
    for (int m = 0; m < 6; m++)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (D[i][m] + D[m][j] < D[i][j] && (i != j && i != m && j != m)) {
                    D[i][j] = D[i][m] + D[m][j];
                    S[i][j] = m;
                }
            }
        }
    }
}
