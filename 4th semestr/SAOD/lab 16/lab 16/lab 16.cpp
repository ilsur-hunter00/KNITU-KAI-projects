#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int Hash(string key) {
	int Amount = 0;
	for (unsigned int i = 0; i < key.size(); i++)
		Amount += key[i];
	return Amount % 10;
}

string* Create() {
	int Count = 10;
	string* Table = new string[Count];
	system("cls");
	int i = 0;
	while (i < Count) {
		string key;
		int Index;
		cout << endl << "Введите ключ" << " " << i + 1 << " из " << 10 << " " << ": ";
		cin >> key;
		Index = Hash(key);
		system("cls");
		if (Table[Index].empty()) {
			Table[Index] = key;
			i++;
		}
		else {
			cout << endl << "Конфликт. Введите другое слово" << endl;
		}
	}
	return Table;
}
//program, then, set, nil, with, in, until, while, Mod, var
int Search(string key, string* Table) {
	int Index = Hash(key);
	if (Table[Index] == key)
		return Index;
	else
		return -1;
}

void Show(string* Table) {
	for (int i = 0; i < 10; i++)
		cout << "Таблица[" << i << "] = " << Table[i] << endl;
}

int main() {
	setlocale(LC_ALL, "rus");
	string* Table = nullptr;
	string key;
	int isCreated = 0;
	char flag;
	int select = 0;
	while (select != 4) {

		cout << "1. Создать таблицу" << endl;
		cout << "2. Вывод таблицы" << endl;
		cout << "3. Поиск" << endl;
		cout << "4. Выход из программы" << endl;
		
		cin >> select;
		
		if (select == 1) {
			if (Table != nullptr) {
				delete[] Table;
				Table = nullptr;
			}
			Table = Create();
			isCreated = 1;
		}
		if (select == 2) {
			if (isCreated != 0)
				Show(Table);
			else
				cout << "\nСперва создайте таблицу" << endl;
			getchar();
			getchar();
		}
		if (select == 3) {
			if (isCreated != 0) {
				system("cls");
				cout << "Введите значение ключа: ";
				cin >> key;
				if (Search(key, Table) != -1)
					cout << "\nИндекс: " << Search(key, Table) << endl;
				else
					cout << "\nНе найдено" << endl;
				getchar();
				getchar();
			}
			else
				cout << "\nСперва создайте таблицу" << endl;
		}
		if (select == 4) {
			break;
		}
		system("pause");
		system("cls");
	}
}