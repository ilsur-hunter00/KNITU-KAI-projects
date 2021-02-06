#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct LaTree {
	int inf;
	LaTree* Left, *Right;
};

struct LaStack {
	int inf;
	LaStack* next;
	LaTree* tree;
};
LaStack* stack;

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

void NoRecurs(LaTree* Root)
{
	int level = -1;
	LaTree* current = Root;
	LaStack* pTemp;
	bool Stop = false;
	while (!(Stop)) // основной цикл обхода
	{
		while (current != NULL) 
		{
			level++;
			pTemp = new LaStack;
			pTemp->tree = current;
			pTemp->inf = level;
			pTemp->next = stack;
			stack = pTemp;
			current = current->Left;
		}
		if (stack == NULL)
		{
			Stop = true;
		}
		else
		{
			current = stack->tree;
			level = stack->inf;
			for (int i = 0; i < stack->inf; i++)
			{
				printf("    ");
			}
			printf("%d\n", current->inf);
			pTemp = stack;
			stack = stack->next;
			delete pTemp;
			current = current->Right;
		}
	}
}

void main() {
	setlocale(LC_ALL, "rus");
	int n;
	LaTree* Root = new LaTree;
	Root = NULL;
	LaStack* stack;
	int select = 0;
	while (select != 6) {
		cout << "1. Создать дерево" << endl;
		cout << "2. Вывод в прямом порядке" << endl;
		cout << "3. Вывод в симметричном порядке" << endl;
		cout << "4. Вывод в обратно-симметричном порядке" << endl;
		cout << "5. Симметричный вывод (нерекурсивный)" << endl;
		cout << "6. Выход из программы" << endl;

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
			NoRecurs(Root);
			system("pause");
		}
		else if (select == 6) {
			break;
		}
		system("cls");
	}
}
