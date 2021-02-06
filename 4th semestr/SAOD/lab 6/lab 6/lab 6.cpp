#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

const int N = 3;
int num = 0;
int numSup = 0;

struct LaList {
	int data;
	LaList* next;
};

LaList* pHead;
LaList* supportList;

struct List {

	void Show() {
		LaList* current = pHead;
		for (int i = 0; i < num; i++) {
			current = current->next;
			printf("%d\n", current->data);
		}
		if (num == 0) {
			cout << "Список пуст" << endl;
		}
	}

	void pushStart() {
		system("cls");
		cout << "Введите новый элемент: " << endl;
		int newEl;
		cin >> newEl;
		LaList* current = new LaList;
		current->data = newEl;
		pHead->next = current;
		current->next = NULL;
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
			cout << "Введите значение предшествующего элемента" << endl;
			cin >> prev;
			LaList* current = pHead->next;
			for (int i = 0; i < num; i++) {
				if (current->data == prev) {
					int newEl;
					cout << "Значение нового элемента: " << endl;
					cin >> newEl;
					LaList* pTemp = new LaList;
					pTemp->data = newEl;
					pTemp->next = current->next;
					current->next = pTemp;
					num++;
					cout << "Элемент добавлен!" << endl;
				}
				current = current->next;
			}
		}
	}

	void pushBefore() {
		if (num == 0) {
			pushStart();
		}
		else {
			int aft;
			cout << "Введите значение последующего элемента" << endl;
			cin >> aft;
			LaList* last = pHead;
			LaList* current = pHead->next;
			for (int i = 0; i < num; i++) {
				if (current->data == aft) {
					int newEl;
					cout << "Значение нового элемента: " << endl;
					cin >> newEl;
					LaList* pTemp = new LaList;
					pTemp->data = newEl;
					pTemp->next = current;
					last->next = pTemp;
					num++;
					return;
				}
				last = last->next;
				current = current->next;
			}
		}
	}

	void Delete() {
		if (num == 0) {
			cout << "Список пуст!" << endl;
		}
		else
		{
			int a;
			cout << "Введите значение удаляемого элемента" << endl;
			cin >> a;
			LaList* current = pHead->next;
			LaList* pPrev = pHead; //предшественник
			for (int i = 0; i < num; i++) {
				if (current->data == a) {
					LaList* del = current->next;
					pPrev->next = del;
					num--;
					current->next = supportList;
					supportList = current;
					numSup++;
					break;
				}
				current = current->next;
				pPrev = pPrev->next;
			}
		}
	}

	void Search() {
		if (num != 0) {
			int a;
			int k = 0;
			cout << "Введите значение для поиска: " << endl;
			cin >> a;
			LaList* current = pHead->next;
			for (int i = 0; i < num; i++) {
				if (current->data == a)
					k++;
				current = current->next;
			}
			printf("Найдено %d элементов\n", k);
		}
		else
		{
			cout << "Список пуст! " << endl;
		}
	}
};

void Supp(LaList* pHead) {
	LaList* current = pHead;
	cout << "Вспомогательный список: " << endl;
	for (int i = 0; i < numSup; i++) {
		printf("%d\n", current->data);
		current = current->next;
	}
	if (numSup == 0) {
		cout << "Список пуст!" << endl;
	}
}

void main() {
	setlocale(LC_ALL, "rus");
	List list;
	pHead = new LaList;
	pHead->next = NULL;
	supportList = new LaList;
	supportList->next = NULL;
	int select = 0;
	while (select != 7) {
		cout << "1. Вывести список на экран" << endl;
		cout << "2. Добавить элемент после заданного" << endl;
		cout << "3. Добавить элемент до заданного" << endl;
		cout << "4. Удалить элемент из списка" << endl;
		cout << "5. Поиск элемента" << endl;
		cout << "6. Вывести вспомогательный список на экран" << endl;
		cout << "7. Выход из программы" << endl;

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
			Supp(supportList);
			system("pause");
		}
		else if (select == 7) {
			break;
		}
		system("cls");
	}
}