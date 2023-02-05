#include <iostream>
#include <queue>
#include <stack>
#include <list>
#include <vector>

using namespace std;

int SpisReb[11][2] = { {1,5}, {1, 2}, {5, 6}, {6, 4}, {6, 9}, {9, 10}, {9, 4}, {2, 7}, {7, 8}, {8, 2}, {8, 3} };

bool MatrixSmej[10][10]
{
	{0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0, 1, 0, 0, 1, 0}, 
	{0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
	{0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
};

vector <vector <int>> SpisSmej = {
	{2, 5},
	{1, 7, 8},
	{8},
	{6, 9},
	{1, 6},
	{4, 5, 9},
	{2, 8},
	{2, 3, 7},
	{4, 6, 10},
	{9}
};

list <int> Mechen;

bool CheckVal(int v)
{
	list <int>::iterator i;
	for (i = Mechen.begin(); i != Mechen.end(); i++)
	{
		if (v == *i) return false;
	}
	return true;
}

void BFS(int v)
{
	if (v <= 0 || v > 10) { cout << "Выбрана неправильная вершина"; return; }
	queue<int> myQueue;
	myQueue.push(v);

	while (!myQueue.empty())
	{
		v = myQueue.front();
		if (CheckVal(v)) cout << v << ' ';
		myQueue.pop();
		Mechen.push_front(v);
		

		for (int i = 0; i < SpisSmej[v - 1].size(); i++)
		{
			if (CheckVal(SpisSmej[v - 1][i])) { myQueue.push(SpisSmej[v - 1][i]); }
		}
	}
}

void DFS(int v)
{
	if (v <= 0 || v > 10) { cout << "Выбрана неправильная вершина"; return; }
	stack<int> myStack;
	myStack.push(v);

	while (!myStack.empty())
	{
		v = myStack.top();
		if(CheckVal(v)) cout << v << ' ';
		myStack.pop();
		Mechen.push_front(v);
		for (int i = SpisSmej[v - 1].size() - 1; i >= 0; i--)
		{
			if (CheckVal(SpisSmej[v - 1][i])) { myStack.push(SpisSmej[v - 1][i]); }
		}
	}
}

int main()
{
    setlocale(LC_ALL, "RUS");
    BFS(8);
	Mechen.clear();
	cout << endl;
	DFS(8);
}