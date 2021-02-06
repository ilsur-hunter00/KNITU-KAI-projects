#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int num = 0;

struct LaList
{
	int data;
	LaList *right, *left;
};

struct List {
	LaList* pHead;

	List() {
		pHead = new LaList;
		pHead->right = pHead;
		pHead->left = pHead;
	}

	void Show() {
		LaList* current = pHead->right;
		LaList* current1 = pHead->left;
		if (num == 0) {
			printf("Список пуст\n");
		}
		else
		{
			int direction;
			cout << "1: Прямой" << endl;
			cout << "2: Обратный" << endl;
			cin >> direction;
			cout << "" << endl;
			if (direction == 1) {
				while (current != pHead) {
					printf("%d\n", current->data);
					current = current->right;
				}
			}
			if (direction == 2) {
				while (current1 != pHead) {
					printf("%d\n", current1->data);
					current1 = current1->left;
				}
			}
		}
	}

	void pushStart() {
		system("cls");
		cout << "Введите новый элемент" << endl;
		int newEl;
		cin >> newEl;
		LaList* current = pHead->right;
		LaList* ptemp = new LaList;
		ptemp->data = newEl;
		ptemp->right = current->right;
		ptemp->left = current;
		current->right->left = ptemp;
		current->right = ptemp;
		num++;
		cout << "Элемент добавлен!" << endl;
	}

	void pushAfter() {
		if (num == 0) {
			pushStart();
		}
		else
		{
			int prev;
			int direction;
			cout << "1: Прямой" << endl;
			cout << "2: Обратный" << endl;
			cin >> direction;
			cout << "Введите значение предшествующего элемента" << endl;
			cin >> prev;
			if (direction == 1) {
				LaList* current = pHead->right;
				do {
					if (current->data == prev) {
						int newEl;
						cout << "Значение нового элемента: " << endl;
						cin >> newEl;
						LaList* ptemp = new LaList;
						ptemp->data = newEl;
						ptemp->right = current->right;
						ptemp->left = current;
						current->right->left = ptemp;
						current->right = ptemp;
						num++;
						cout << "Элемент добавлен!" << endl;
						return;
					}
					current = current->right;
				} while (current != pHead);
			}
			else {
				LaList* current1 = pHead->left;
				do {
					if (current1->data == prev) {
						int newEl;
						cout << "Значение нового элемента: " << endl;
						cin >> newEl;
						LaList* ptemp = new LaList;
						ptemp->data = newEl;
						ptemp->left = current1->left;
						ptemp->right = current1;
						current1->left->right = ptemp;
						current1->left = ptemp;
						num++;
						cout << "Элемент добавлен!" << endl;
						return;
					}
					current1 = current1->left;
				} while (current1 != pHead);
			}
		}
	}

	void pushBefore() {
		if (num == 0) {
			pushStart();
		}
		else
		{
			int aft;
			int newEl;
			int direction;
			cout << "1: Прямой" << endl;
			cout << "2: Обратный" << endl;
			cin >> direction;
			cout << "Введите значение последующего элемента" << endl;
			cin >> aft;
			LaList* current = pHead->right;
			LaList* current1 = pHead->left;
			if (direction == 1) {
				while (current != pHead) {
					if (current->data == aft) {
						cout << "Значение нового элемента: " << endl;
						cin >> newEl;
						LaList* ptemp = new LaList;
						ptemp->data = newEl;
						ptemp->left = current->left;
						ptemp->right = current;
						current->left->right = ptemp;
						current->left = ptemp;
						num++;
						cout << "Элемент добавлен!" << endl;
						return;
					}
					current = current->right;
				}
			}
			if (direction == 2) {
				while (current1 != pHead) {
					if (current1->data == aft) {
						cout << "Значение нового элемента: " << endl;
						cin >> newEl;
						LaList* ptemp = new LaList;
						ptemp->data = newEl;
						ptemp->right = current1->right;
						ptemp->left = current1;
						current1->right->left = ptemp;
						current1->right = ptemp;
						num++;
						cout << "Элемент добавлен!" << endl;
						return;
					}
					current1 = current1->left;
				}
			}
		}
	}

	void Delete() {
		if (num == 0) {
			cout << "Список пуст!" << endl;
		}
		else
		{
			int del;
			int direction;
			LaList* current1 = pHead->left;
			LaList* current = pHead->right;
			cout << "1: Прямой" << endl;
			cout << "2: Обратный" << endl;
			cin >> direction;
			cout << "Введите значение удаляемого элемента" << endl;
			cin >> del;
			if (direction == 1) {
				while (current != pHead) {
					if (current->data == del) {
						current->left->right = current->right;
						current->right->left = current->left;
						delete current;
						num--;
						cout << "Элемент удалён!" << endl;
						return;
					}
					current = current->right;
				}
			}
			if (direction == 2) {
				while (current1 != pHead) {
					if (current1->data == del) {
						current1->left->right = current1->right;
						current1->right->left = current1->left;
						delete current1;
						num--;
						cout << "Элемент удалён!" << endl;
						return;
					}
					current1 = current1->left;
				}
			}
		}
	}

	void Search() {
		if (num != 0) {
			int search;
			int direction;
			int k = 0;
			cout << "Введите значение для поиска: " << endl;
			cin >> search;
			LaList* current = pHead->right;
			LaList* current1 = pHead->left;
			cout << "1: Прямой" << endl;
			cout << "2: Обратный" << endl;
			cin >> direction;
			if (direction == 1) {
				while (current != pHead) {
					if (current->data == search) {
						k++;
					}
					current = current->right;
				}
			}
			if (direction == 2) {
				while (current1 != pHead) {
					if (current1->data == search) {
						k++;
					}
					current1 = current1->left;
				}
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

		else if (select == 6) {
			break;
		}
		system("cls");
	}
}