#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct LaTree {
	int inf;
	LaTree* Left, * Right;
};


void Forward(LaTree* current, int level) {
	if (current != NULL) {
		for (int i = 0; i < level; i++) {
			printf("    ");
		}
		printf("%d\n", current->inf);
		level++;
		Forward(current->Left, level);
		Forward(current->Right, level);
	}
}

void Symmetr(LaTree* current, int level) {
	if (current != NULL) {
		level++;
		Symmetr(current->Left, level);
		for (int i = 0; i < level - 1; i++) {
			printf("    ");
		}
		printf("%d\n", current->inf);
		Symmetr(current->Right, level);
	}
}

void Rev_Symmetr(LaTree* current, int level) {

	if (current != NULL) {
		level++;
		Rev_Symmetr(current->Right, level);
		for (int i = 0; i < level - 1; i++) {
			printf("    ");
		}
		printf("%d\n", current->inf);
		Rev_Symmetr(current->Left, level);
	}
}

void Create(LaTree** current, int n) {
	int N_l;
	int N_r;
	if (n == 0) {
		*current = NULL;
	}
	else {
		LaTree* pTemp = new LaTree;
		pTemp->inf = 1 + rand() % 99;
		N_l = n / 2;
		N_r = n - N_l - 1;
		Create(&pTemp->Left, N_l);
		Create(&pTemp->Right, N_r);
		*current = pTemp;
	}
}

void main() {
	setlocale(LC_ALL, "rus");
	int n;
	LaTree* Root = new LaTree;
	Root = NULL;
	int select = 0;
	while (select != 5) {
		cout << "1. Создать дерево" << endl;
		cout << "2. Вывод в прямом порядке" << endl;
		cout << "3. Вывод в симметричном порядке" << endl;
		cout << "4. Вывод в обратно-симметричном порядке" << endl;
		cout << "5. Выход из программы" << endl;

		cin >> select;
		system("cls");
		if (select == 1) {
			cout << "Введите количество вершин дерева" << endl;
			cin >> n;
			Create(&Root, n);
			system("pause");
		}
		else if (select == 2) {
			Forward(Root, 0);
			system("pause");
		}
		else if (select == 3) {
			Symmetr(Root, 0);
			system("pause");
		}
		else if (select == 4) {
			Rev_Symmetr(Root, 0);
			system("pause");
		}
		else if (select == 5) {
			break;
		}
		system("cls");
	}
}
