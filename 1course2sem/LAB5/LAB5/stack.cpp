#include <iostream>
#include "ST.h"
using namespace std;

void skobki(string str)
{
	stack <char> steck;
	bool correct = true;
	steck.push(0);
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '(') steck.push(')');
		if (str[i] == '{') steck.push('}');
		if (str[i] == '[') steck.push(']');
	}
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (steck.top() == str[i]) correct = false;
	}
}