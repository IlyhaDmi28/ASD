#include "stdfax.h"

vector<vector<short>> setVersh;
vector<short> subsetVersh;

bool ChechPozition(int Imin, int Jmin)
{
    bool HasI = false, HasJ = false;
    short x = 0, c = 0;
    for (short i = 0; i < setVersh.size(); i++)
    {
        for (short j = 0; j < setVersh[i].size(); j++)
        {
            if (Imin == setVersh[i][j])
            {
                //setVersh[i].push_back(Jmin);
                HasI = true;
                c = i;
                break;
            }
            if (Jmin == setVersh[i][j])
            {
                //setVersh[i].push_back(Imin);
                HasJ = true;
                c = i;
                break;
            }
        }
    }
    if (HasI && HasJ) return false;
    else if (HasI) { setVersh[c].push_back(Jmin); return false; }
    else if (HasJ) { setVersh[c].push_back(Imin); return false; }
    else return true;
}

short GetSizeSets()
{
    short SizeSets = 0;
    for (short i = 0; i < setVersh.size(); i++)
    {
        SizeSets += setVersh[i].size();
    }
    return SizeSets;
}

int D0[8][8] = {
    {0, 2, 0, 8, 2, 0, 0, 0 },
    {2, 0, 3, 10, 5, 0, 0, 0},
    {0, 3, 0, 0, 12, 0, 0, 7},
    {8, 10, 0, 0, 14, 3, 1, 0},
    {2, 5, 12, 14, 0, 11, 4, 8},
    {0, 0, 0, 3, 11, 0, 6, 0},
    {0, 0, 0, 1, 4, 6, 0, 9},
    {0, 0, 7, 0, 8, 0, 9, 0}
};

int D1[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0 },
    {0, 0, 0, 0, 0, 0, 0, 0 },
    {0, 0, 0, 0, 0, 0, 0, 0 },
    {0, 0, 0, 0, 0, 0, 0, 0 },
    {0, 0, 0, 0, 0, 0, 0, 0 },
    {0, 0, 0, 0, 0, 0, 0, 0 },
    {0, 0, 0, 0, 0, 0, 0, 0 },
    {0, 0, 0, 0, 0, 0, 0, 0 }
};

void Krascale() 
{
    while (GetSizeSets() != 8)
    {
        subsetVersh.clear();

        short min = INT16_MAX, Imin = 0, Jmin = 0;

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (min > D0[i][j] && D0[i][j]) {
                    min = D0[i][j];
                    Imin = i;
                    Jmin = j;
                }
            }
        }

       

        if (ChechPozition(Imin, Jmin))
        {
            if (Imin > Jmin)
            {
                subsetVersh.push_back(Imin);
                subsetVersh.push_back(Jmin);
            }
            else
            {
                subsetVersh.push_back(Jmin);
                subsetVersh.push_back(Imin);
            }
            setVersh.push_back(subsetVersh);
        }

        D0[Imin][Jmin] = 0;
        D0[Jmin][Imin] = 0;

        D1[Imin][Jmin] = min;
        D1[Jmin][Imin] = min;
    }

    for (short i = 0; i < setVersh.size(); i++)
    {
        for (short j = 0; j < setVersh[i].size(); j++)
        {
            subsetVersh.push_back(setVersh[i][j]);
        }
    }

    for (short i = 0; i < 8; i++)
    {
        cout << subsetVersh[i] << ' ';
    }
}