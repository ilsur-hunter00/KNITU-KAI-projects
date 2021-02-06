#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

const int Num = 25;

struct LaList
{
	char massive[Num];
	int c;
};

struct List {

	LaList* list = new LaList;

	List() {
		list->c = 0;
	}

	int search(int current) {
		if (list->c == 0) {
			return -2;
		}
		for (int i = 0; i < list->c; i++) {
			if (list->massive[i] > current) {
				return i;
			}
		}
		return -1;
	}

	int searchDel(int current) {
		int k = -1;
		if (list->c == 0) {
			cout << "Список пуст!" << endl;
			return -2;
		}
		for (int i = 0; i < list->c; i++) {
			if (list->massive[i] == current) {
				k = i;
				cout << "Номер элемента:" << k + 1 << endl;
			}
		}
		return k;
	}

	void Push() {
		if (list->c == Num) {
			cout << "Список полон!" << endl;
			return;
		}
		int info;
		cout << "Введите элемент:" << endl;
		cin >> info;
		if (list->c != 0) {
			int _search = search(info);
			if (_search == -1) {
				list->massive[list->c] = info;
				list->c++;
				return;
			}
			for (int i = list->c; i > _search - 1; i--) {
				list->massive[i] = list->massive[i - 1];
			}
			list->massive[_search] = info;
		}
		else if (list->c == 0) {
			list->massive[0] = info;
		}
		list->c++;
	}

	void Delete(int current) {
		if (list->c == 0) {
			cout << "Список пуст!" << endl;
			return;
		}
		int _search = searchDel(current);
		if (_search == -1) {
			cout << "Такого элемента в списке нет!" << endl;
			return;
		}
		for (int i = _search; i < list->c - 1; i++) {
			list->massive[i] = list->massive[i + 1];
		}
		list->c--;
	}

	void Show() {
		if (list->c == 0) {
			cout << "Список пуст!" << endl;
			return;
		}
		for (int i = 0; i < list->c; i++) {
			printf("%d\n", list->massive[i]);
		}
	}


};

void main() {
	using namespace std;
	setlocale(LC_ALL, "rus");
	List list;
	int select = 0;
	while (select != 5) {
		cout << "1.Добавить элемент" << endl;
		cout << "2.Удалить элемент" << endl;
		cout << "3.Вывод списка" << endl;
		cout << "4.Найти элемент" << endl;
		cout << "5.Выход из программы" << endl;
		cin >> select;
		cout << "" << endl;
		if (select == 1) {
			list.Push();
			system("pause");
		}
		else if (select == 2) {
			int current;
			cout << "Введите элемент, который хотите удалить.\n" << endl;
			cin >> current;
			cout << "" << endl;
			list.Delete(current);
			system("pause");
		}
		else if (select == 3) {
			cout << "" << endl;
			list.Show();
			system("pause");
		}
		else if (select == 4) {
			int current;
			cout << "Введите элемент, который хотите найти.\n" << endl;
			cin >> current;
			cout << "" << endl;
			int search = list.searchDel(current);
			if (search == -2) {
				printf("Список пуст.\n");
			}
			else if (search == -1) {
				printf("Такого элемента в списке нет!");
			}
			system("pause");
		}
		else if (select == 5) {
			break;
		}
		system("cls");
	}
}