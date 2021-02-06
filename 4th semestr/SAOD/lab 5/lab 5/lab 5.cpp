#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

const int N = 5;

int num = 0; //кол-во эл-ов

struct LaList {
	int data;
	int Next;
};


struct List {

	LaList list[N];

	List() {
		list[0].Next = 0;
		for (int i = 1; i < N; i++) {
			list[i].Next = -1;
		}
	}

	void Show() {
		int current = list[0].Next;
		for (int i = 0; i < num; i++) {
			printf("%d\n", list[current].data);
			current = list[current].Next;
		}
		if (num == 0) {
			cout << "Список пуст!" << endl;
		}
	}

	int Poisk() {
		int k = 0;
		for (int i = 1; i < N; i++) {
			if (list[i].Next == -1) {
				k = i;
				break;
			}
		}
		return k;
	}

	void pushStart(int k) {
		system("cls");
		cout << "Введите новый элемент:" << endl;
		int newEl;
		cin >> newEl;
		list[k].Next = list[num].Next;
		list[num].Next = k;
		num++;
		list[k].data = newEl;
		cout << "Элемент добавлен" << endl;
	}

	void pushAfter() {
		int k = Poisk();
		if (k != 0) {
			if (num == 0) {
				pushStart(k);
			}
			else {
				int prev; //предыдущий эл-т
				int count = 0;
				cout << "Введите значение предшествующего элемента" << endl;
				cin >> prev;
				int current = list[0].Next;
				for (int i = 0; i < num; i++) {
					if (list[current].data == prev) {
						if (num < N) {
							int newEl;
							cout << "Значение нового элемента: " << endl;
							cin >> newEl;
							list[k].Next = list[current].Next;
							list[current].Next = k;
							list[k].data = newEl;
							num++;
							cout << "Элемент добавлен" << endl;
						}
						else {
							cout << "Список полон!" << endl;
						}
						break;
					}
					current = list[current].Next;
				}
			}
		}
		else {
			cout << "Список полон!" << endl;
		}
	}

	void pushBefore() {
		int k = Poisk();
		if (k != 0) {
			if (num == 0) {
				pushStart(k);
			}
			else {
				int aft;
				cout << "Введите значение последующего элемента" << endl;
				cin >> aft;
				int current = list[0].Next;
				int last = 0;
				for (int i = 0; i < num; i++) {
					if (list[current].data == aft) {
						int newEl;
						cout << "Значение нового элемента: " << endl;
						cin >> newEl;
						if (num < N) {
							list[k].Next = current;
							list[last].Next = k;
							list[k].data = newEl;
							num++;
						}
						break;
					}
					current = list[current].Next;
					last = list[last].Next;
				}
			}
		}
		else {
			cout << "Список полон!" << endl;
		}
	}

	void Delete() {
		if (num == 0) {
			cout << "Список пуст!" << endl;
		}
		else {
			int a;
			cout << "Введите значение элемента, которое вы хотите удалить:" << endl;
			cin >> a;
			int current = list[0].Next; //индекс удаляемого эл-та
			int last = 0; // индекс его предшественника
			for (int i = 0; i < num; i++) {
				if (list[current].data == a) {
					list[last].Next = list[current].Next;
					list[current].Next = -1;
					num--;
					cout << "Элемент удалён!" << endl;
					break;
				}
				current = list[current].Next;
				last = list[last].Next;
			}
		}
	}

	void Search() {
		if (num != 0) {
			int a;
			int k = 0;
			cout << "Введите значение для поиска:" << endl;
			cin >> a;
			int current = list[0].Next;
			for (int i = 0; i < num; i++) {
				if (list[current].data == a)
					k++;
				current = list[current].Next;
			}
			printf("Найдено %d элементов\n", k);
		}
		else {
			cout << "Список пуст!" << endl;
		}
	}
};

void main() {
	setlocale(LC_ALL, "rus");
	List list;
	int select = 0;
	while (select != 6) {
		cout << "1. Вывести список на экран" << endl;
		cout << "2. Добавить элемент после заданного" << endl;
		cout << "3. Добавить элемент до заданного" << endl;
		cout << "4. Удалить элемент из списка" << endl;
		cout << "5. Поиск элемента" << endl;
		cout << "6. Выход из программы" << endl;
		
		cin >> select;
		system("cls");
		if (select == 1) {
			list.Show();
			system("pause");
		}
		else if (select == 2) {
			list.pushAfter();
			system("pause");
		}
		else if (select == 3) {
			list.pushBefore();
			system("pause");
		}
		else if (select == 4) {
			list.Delete();
			system("pause");
		}
		else if (select == 5) {
			list.Search();
			system("pause");
		}
		else if (select == 6)  {
			break;
		}
		system("cls");
	}
}