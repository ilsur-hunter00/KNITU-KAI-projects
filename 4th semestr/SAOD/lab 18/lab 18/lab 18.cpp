#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

const int m = 12;

int Hash(string key) {
	int sum = 0;
	for (int i = 0; i < key.size(); i++)
		sum += key[i];
	return sum % m;
}

struct El {
	string key;
	El* next;
};

struct LaList {
	string key;
	El* Head;
};

LaList list[m];

El* GetElement(int Index, int* count1) {
	El* CurrentEl = list[Index].Head;
	while (++(*count1) && CurrentEl->next != nullptr)
		CurrentEl = CurrentEl->next;
	return CurrentEl;
}

int Add(string key) {
	int count1 = 0;
	int Index = Hash(key);
	if (++count1 && list[Index].key.empty())
		list[Index].key = key;
	else {
		cout << "\nКонфликт!" << endl;
		El* CurrentEl = GetElement(Index, &count1);
		CurrentEl->next = new El;
		CurrentEl->next->key = key;
		CurrentEl->next->next = nullptr;
	}
	return count1;
}

bool Search(string key, int* count1) {
	bool flag = false;
	int Index = Hash(key);
	if (++(*count1) && list[Index].key == key)
		flag = true;
	else {
		El* Temp = list[Index].Head->next;
		while (++(*count1) && Temp != nullptr) {
			if (Temp->key == key) {
				flag = true;
				break;
			}
			Temp = Temp->next;
		}
	}
	return flag;
}

void Show() {
	cout << endl;
	for (int i = 0; i < m; i++) {
		cout << "[" << i+1 << "]  " << list[i].key << " ";
		El* Temp = list[i].Head->next;
		while (Temp != nullptr) {
			cout << Temp->key << " ";
			Temp = Temp->next;
		}
		cout << endl;
	}
}

bool Delete(string key) {
	int hash = Hash(key);
	bool flag = false;
	if (list[hash].key == key) {
		if (list[hash].Head->next == nullptr) {
			flag = true;
			list[hash].key = "";
		}
		else {
			list[hash].key = list[hash].Head->next->key;
			El* Temp = list[hash].Head->next;
			list[hash].Head->next = Temp->next;
			flag = true;
			delete Temp;
		}
	}
	else {
		El* prev = list[hash].Head;
		El* Temp = list[hash].Head->next;
		while (Temp != nullptr) {
			if (Temp->key == key) {
				flag = true;
				prev->next = Temp->next;
				delete Temp;
				break;
			}
			else {
				prev = Temp;
				Temp = Temp->next;
			}
		}
	}
	return flag;
}

int main() {
	setlocale(LC_ALL, "rus");
	string key;
	int count1;

	for (int i = 0; i < m; i++) {
		list[i].key.empty();
		list[i].Head = new El;
		list[i].Head->next = nullptr;
	}

	string select;
	while (true) {
		cout << "1. Добавить ключ" << endl;
		cout << "2. Поиск ключа" << endl;
		cout << "3. Показать таблицу" << endl;
		cout << "4. Удалить ключ" << endl;
		cout << "5. Выход из программы" << endl;

		cin >> select;
		
		if (select == "1") {
			cout << "Введите ключ: "<< endl;
			cin >> key;
			count1 = 0;
			if (Search(key, &count1))
				cout << "\nТакой ключ уже сущетсвует! Количество сравнений: " << count1 << endl;
			else {
				count1 = Add(key);
				cout << "\nКлюч добавлен! Количество сравнений: " << count1 << endl;
			}
		}
		if (select == "2") {
			cout << "Введите ключ: " << endl;
			cin >> key;
			count1 = 0;
			if (Search(key, &count1))
				cout << "\nКлюч найден! Количество сравнений: " << count1 << endl;
			else
				cout << "\nКлюч не найден" << endl;
		}
		if (select == "3") {
			Show();
		}
		if (select == "4") {
			cout << "Введите ключ: " << endl;
			cin >> key;
			if (Delete(key))
				cout << "\nКлюч удален" << endl;
			else
				cout << "\nКлюч не найден" << endl;
		}
		if (select == "5") {
			break;
		}
		
		_getch();
	}
}