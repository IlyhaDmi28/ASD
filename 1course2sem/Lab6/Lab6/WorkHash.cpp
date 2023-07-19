#include "Hash.h"
#include <time.h>

int Hash_Fun(short key)
{
	return key % SIZE;
}

void delALL(HashTab* This, HashTab* Tab)
{
	if (This->colision) delALL(This->colision, Tab);
	if (This = Tab) This->numb = 0;
	else delete This;
}

void add(HashTab *Tab)
{
	short numb;
	cout << "Введите номер: ";
	cin >> numb;
	short key = Hash_Fun(numb);
	if (key >= SIZE)
	{
		cout << "Превышен размер таблицы";
		return;
	}
	HashTab* This = (Tab + key);
	while (true)
	{
		if (key != Hash_Fun(This->numb) || !key)
		{
			This->numb = numb;
			cout << "Введите имя:";
			cin >> This->NAME;
			cout << "Введите Фамилию: ";
			cin >> This->LAST_NAME;
			cout << "Введите Отчество: ";
			cin >> This->OTCHESTVO;
			break;
		}
		else
		{
			if (!This->colision) This->colision = new HashTab;
			This = This->colision;
		}
	}
}

void out(HashTab* Tab)
{
	HashTab* This;
	for (int i = 0; i < SIZE; i++)
	{
		This = Tab + i;
		if (This->numb)
		{
			while (true)
			{
				cout << "Номер: " << This->numb << endl;
				cout << "Имя: " << This->NAME << endl;
				cout << "Фамилия: " << This->LAST_NAME << endl;
				cout << "Отчество: " << This->OTCHESTVO << endl;
				cout << "------------------------------------------------------------------------------------------------------------" << endl;
				if (This->colision) This = This->colision;
				else break;
			}
		}
	}
}

void find(HashTab* Tab)
{
	clock_t nowTime, deltaTime;
	double Time;

	short numb;
	cout << "Введите номер людей, данные которых вы хотите просмтореть: ";
	cin >> numb;
	short key = Hash_Fun(numb);

	nowTime = clock();
	HashTab* This = (Tab + key);

	while (true)
	{
		if (!This->numb) {
			cout << "Людей, с такими номерами нет!" << endl;
			break;
		}
		else
		{
			cout << "Номер: " << This->numb << endl;
			cout << "Имя: " << This->NAME << endl;
			cout << "Фамилия: " << This->LAST_NAME << endl;
			cout << "Отчество: " << This->OTCHESTVO << endl;
			cout << "------------------------------------------------------------------------------------------------------------" << endl;
			if (This->colision) This = This->colision;
			else break;
		}
	}
	deltaTime = clock();
	Time = ((double)deltaTime - (double)nowTime) / (double)CLOCKS_PER_SEC;
	cout << "Время поиска: " << Time << endl;
}

void del(HashTab* Tab)
{
	short numb;
	cout << "Введите номер людей, данные которых вы хотите удалить: ";
	cin >> numb;
	int key = Hash_Fun(numb);
	if (!Tab[key].numb) {
		cout << "Людей, с такими номерами нет!" << endl;
	}
	else
	{
		HashTab* This = (Tab + key);
		delALL(This, Tab + key);
	}
}