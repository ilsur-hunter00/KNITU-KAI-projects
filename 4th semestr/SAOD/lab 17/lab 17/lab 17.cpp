#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

const int m = 10;
const int n = 1.2 * m;

int Hash(string key) {
	int sum = 0;
	for (unsigned int i = 0; i < key.size(); i++)
		sum += key[i];
	return sum % n;
}

void Show(string mass[]) {
	for (int i = 0; i < n; i++) {
		cout << "[" << i + 1 << "]" << mass[i] << " " << endl;
	}
}

void Search(string mass[], string str) {
	int hash;
	string keyy;
	cout << "\nВведите ключевое слово для поиска\n";
	cin >> keyy;
	hash = Hash(keyy);
	int count1 = 1;
	if (mass[hash] == "") {
		cout << "\nТакой элемент не найден \nКоличество сравнений: " << count1 << endl;
	}
	else if (mass[hash] == keyy) {
		cout << "\nЭлемент найден, его индекс - [" << hash + 1<< "]" << "\nКоличество сравнений: " << count1 << endl;
	}
	else {
		for (int i = 1; i < n; i++) {
			hash = (hash + 1) % n;
			count1++;
			if (mass[hash] == "" || i == n - 1 && mass[hash] != keyy) {
				cout << "\nЭлемент не найден!\nКоличество сравнений: " << count1 << endl;
				break;
			}
			else if (mass[hash] == keyy) {
				cout << "\nЭлемент найден, его индекс - [" << hash + 1 << "]" << "\nКоличество сравнений: " << count1 << endl;
				break;
			}
		}
	}
}

void AddNewKey(string mass[], int& count) {
	string keyy;
	cout << "\nВведите ключ: \n";
	cin >> keyy;
	int hash;
	hash = Hash(keyy);
	int count1 = 1;
	if (mass[hash] == "") {
		mass[hash] = keyy;
		cout << "\nКлюч добавлен\nКоличество сравнений: " << count1 << endl;
		count++;
	}
	else if (mass[hash] == keyy) {
		cout << "\nТакой ключ уже есть\nКоличество сравнений: " << count1 << endl;
	}
	else {
		for (int i = 1; i < n; i++) {
			hash = (hash + 1) % n;
			count1++;
			if (mass[hash] == "") {
				mass[hash] = keyy;
				cout << "\nКлюч добавлен\nКоличество сравнений: " << count1 << endl;
				count++;
				break;
			}
			else if (mass[hash] == keyy) {
				cout << "\nТакой ключ уже есть\nКоличество сравнений: " << count1 << endl;
				break;
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	string Table[n];
	string str;
	int Count = 0;
	string operation;
	string select;

	while (true) {
		cout << "1. Добавить ключ" << endl;
		cout << "2. Поиск ключа" << endl;
		cout << "3. Показать таблицу" << endl;
		cout << "4. Выход из программы" << endl;

		cin >> select;

		if (select == "1") {
			if (Count != m)
				AddNewKey(Table, Count);
			else
				cout << "В таблице нет свободных ячеек. Добвить новый ключ невозможно" << endl;
		}
		else if (select == "2") {
			if (Count != 0) {
				Search(Table, str);
			}
			else
				cout << "Таблица пуста" << endl;

		}
		else if (select == "3") {
			Show(Table);
			cout << endl;
		}
		else if (select == "4") {
			break;
		}
	}
}