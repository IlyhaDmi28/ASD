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
	cout << "������� �����: ";
	cin >> numb;
	short key = Hash_Fun(numb);
	if (key >= SIZE)
	{
		cout << "�������� ������ �������";
		return;
	}
	HashTab* This = (Tab + key);
	while (true)
	{
		if (key != Hash_Fun(This->numb) || !key)
		{
			This->numb = numb;
			cout << "������� ���:";
			cin >> This->NAME;
			cout << "������� �������: ";
			cin >> This->LAST_NAME;
			cout << "������� ��������: ";
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
				cout << "�����: " << This->numb << endl;
				cout << "���: " << This->NAME << endl;
				cout << "�������: " << This->LAST_NAME << endl;
				cout << "��������: " << This->OTCHESTVO << endl;
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
	cout << "������� ����� �����, ������ ������� �� ������ �����������: ";
	cin >> numb;
	short key = Hash_Fun(numb);

	nowTime = clock();
	HashTab* This = (Tab + key);

	while (true)
	{
		if (!This->numb) {
			cout << "�����, � ������ �������� ���!" << endl;
			break;
		}
		else
		{
			cout << "�����: " << This->numb << endl;
			cout << "���: " << This->NAME << endl;
			cout << "�������: " << This->LAST_NAME << endl;
			cout << "��������: " << This->OTCHESTVO << endl;
			cout << "------------------------------------------------------------------------------------------------------------" << endl;
			if (This->colision) This = This->colision;
			else break;
		}
	}
	deltaTime = clock();
	Time = ((double)deltaTime - (double)nowTime) / (double)CLOCKS_PER_SEC;
	cout << "����� ������: " << Time << endl;
}

void del(HashTab* Tab)
{
	short numb;
	cout << "������� ����� �����, ������ ������� �� ������ �������: ";
	cin >> numb;
	int key = Hash_Fun(numb);
	if (!Tab[key].numb) {
		cout << "�����, � ������ �������� ���!" << endl;
	}
	else
	{
		HashTab* This = (Tab + key);
		delALL(This, Tab + key);
	}
}