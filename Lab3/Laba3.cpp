#include <iostream>
#include <vector>
#include <list>
#include "NumbLetter.h"
using namespace std;

list <int> Visited;

bool CheckVisited(int Versh)
{
	{
		list <int>::iterator i;
		for (i = Visited.begin(); i != Visited.end(); i++)
		{
			if (Versh == *i) return false;
		}
		return true;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	vector <vector <int>> SpisSmej = {
		/*A*/{B, C},
		/*B*/{A, F, G},
		/*C*/{A, E, F},
		/*D*/{E, H, I},
		/*E*/{C, D},
		/*F*/{B, C, H},
		/*G*/{B, I},
		/*H*/{F, D, I},
		/*I*/{D, H, G},
	};
	vector <vector <int>> Distance = {
		/*A*/{7, 10},
		/*B*/{7, 9, 27},
		/*C*/{10, 31, 8},
		/*D*/{32, 17, 21},
		/*E*/{31, 32},
		/*F*/{9, 8, 11},
		/*G*/{27, 15},
		/*H*/{11, 17, 15},
		/*I*/{21, 15, 15}
	};
	char choise;
	int versh = -1;
	do {
		cout << "Выберите стартовую вершину: "; cin >> choise;

		switch (choise)
		{
		case 'A': versh = A; break;
		case 'B': versh = B; break;
		case 'C': versh = C; break;
		case 'D': versh = D; break;
		case 'E': versh = E; break;
		case 'F': versh = F; break;
		case 'G': versh = G; break;
		case 'H': versh = H; break;
		case 'I': versh = I; break;
		default: cout << "Такой вершины нет!" << endl; break;
		}
	} while (versh < 0 || versh > 8);

	vector <float> DistanceСovered = { INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY };

	DistanceСovered[versh] = 0;

	while ( Visited.size() != SpisSmej.size() )
	{
		Visited.push_back(versh);
		for (int j = 0; j < SpisSmej[versh].size(); j++)
		{
			if (CheckVisited(SpisSmej[versh][j])) {
				if ((Distance[versh][j] + DistanceСovered[versh]) < DistanceСovered[SpisSmej[versh][j]]) {
					DistanceСovered[SpisSmej[versh][j]] = Distance[versh][j] + DistanceСovered[versh];
				}
			}
		}
		int min = 0;
		for (int j = 0; j < DistanceСovered.size(); j++)
		{
			if (CheckVisited(j)) {
				min = j; break;
			}
		}
		for (int j = 0; j < DistanceСovered.size(); j++)
		{
			if (DistanceСovered[j] < DistanceСovered[min] && CheckVisited(j)) min = j;
			
		}
		versh = min;
	}

	cout << choise << " -> A = " << DistanceСovered[A] << endl;
	cout << choise << " -> B = " << DistanceСovered[B] << endl;
	cout << choise << " -> C = " << DistanceСovered[C] << endl;
	cout << choise << " -> D = " << DistanceСovered[D] << endl;
	cout << choise << " -> E = " << DistanceСovered[E] << endl;
	cout << choise << " -> F = " << DistanceСovered[F] << endl;
	cout << choise << " -> G = " << DistanceСovered[G] << endl;
	cout << choise << " -> H = " << DistanceСovered[H] << endl;
	cout << choise << " -> I = " << DistanceСovered[I] << endl;
}
