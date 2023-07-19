#pragma once
#include <iostream>
#define SIZE 128
using namespace std;

struct HashTab {
	short numb = 0;
	string NAME;
	string LAST_NAME;
	string OTCHESTVO;
	HashTab *colision = nullptr;
};

int Hash_Fun(short key);

void add(HashTab* Tab);
void find(HashTab* Tab);
void out(HashTab* Tab);
void del(HashTab* Tab);
void delALL(HashTab* This, HashTab* Tab);
