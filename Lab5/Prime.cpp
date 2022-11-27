#include "stdfax.h"

vector<int> poz;

void addPoz(int i, int j)
{
    bool noStr = true;
    bool noColumn = true;

    for (short x = 0; x < poz.size(); x++)
    {
        if (poz[x] == i) noStr = false;
    }
    if (noStr) poz.push_back(i);

    for (short x = 0; x < poz.size(); x++)
    {
        if (poz[x] == j) noColumn = false;
    }
    if (noColumn) poz.push_back(j);
}

struct MIN {
    int val;
    int str;
    int column;
};

int D[8][8] = {
    //  1 2 3 4 5 6
    /*1*/ {0, 2, 0, 8, 2, 0, 0, 0 },
    /*2*/ {2, 0, 3, 10, 5, 0, 0, 0},
    /*3*/ {0, 3, 0, 0, 12, 0, 0, 7},
    /*4*/ {8, 10, 0, 0, 14, 3, 1, 0},
    /*5*/ {2, 5, 12, 14, 0, 11, 4, 8},
    /*6*/ {0, 0, 0, 3, 11, 0, 6, 0},
    /*7*/ {0, 0, 0, 1, 4, 6, 0, 9},
    /*8*/ {0, 0, 7, 0, 8, 0, 9, 0}
};

void Clean()
{
    for (int i = 0; i < poz.size(); i++)
    {
        for (short j = 0; j < 8; j++)
        {
            D[poz[i]][j] = 0;
        }

    }
}

void Prime() 
{
    vector<MIN> mins;

    MIN min;
    min.val = INT_MAX;
    min.str = 0;
    min.column = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (min.val > D[i][j] && D[i][j]) {
                min.val = D[i][j];
                min.str = i;
                min.column = j;
            }
        }
    }

    while (poz.size() != 8)
    {
        mins.push_back(min);
        addPoz(min.str, min.column);

        Clean();

        min.val = INT_MAX;
        min.str = 0;
        min.column = 0;

        for (short i = 0; i < 8; i++)
        {
            for (short j = 0; j < poz.size(); j++)
            {
                if (min.val > D[i][poz[j]] && D[i][poz[j]])
                {
                    min.val = D[i][poz[j]];
                    min.str = i;
                    min.column = poz[j];
                }
            }
        }

    }

    int sum = 0;
    for (short i = 0; i < mins.size(); i++)
    {
        sum += mins[i].val;
    }
    cout << "Длинна прохода: " << sum << endl << endl;

    for (short c = 0; c < mins.size(); c++)
    {
        D[mins[c].str][mins[c].column] = mins[c].val;
    }

    for (short i = 0; i < 8; i++)
    {
        for (short j = 0; j < 8; j++)
        {
            cout << D[i][j] << '\t';
        }
        cout << endl;
    }
}
