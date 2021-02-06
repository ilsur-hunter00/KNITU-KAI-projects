#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct LaTree {
	int inf;
	LaTree* Left;
	LaTree* Right;
};

LaTree* root = NULL;
LaTree* parent = NULL;
bool stop = false;
int num = 0;

void Search(LaTree* tree, int value) {
	if (stop == true) {
		return;
	}
	if (tree != NULL) {
		if (tree->inf == value) {
			stop = true;
			parent = tree;
			return;
		}
		Search(tree->Left, value);
		Search(tree->Right, value);
	}
}

void Add() {
	int newEl;
	if (root == NULL) {
		root = new LaTree;
		cout << "Введите значение информационной части вершины:" << endl;
		cin >> newEl;
		root->inf = newEl;
		root->Left = NULL;
		root->Right = NULL;
	}
	else {
		int inf;
		cout << "Введите информационную часть родительской вершины:" << endl;
		cin >> inf;
		parent = NULL;
		stop = false;
		Search(root, inf);
		if (parent != NULL) {
			cout << "Введите значение вершины, которую нужно добавить:" << endl;
			LaTree* current = new LaTree;
			cin >> current->inf;
			current->Right = NULL;
			current->Left = NULL;
			if (parent->Left == NULL && parent->Right == NULL) {
				int select;
				cout << "1. Добавить в качестве левого потомка" << endl;
				cout << "2. Добавить в качестве правого потомка" << endl;
				cin >> select;
				if (select == 1) {
					parent->Left = current;
				}
				else if (select == 2) {
					parent->Right = current;
				}
			}
			else {
				if (parent->Left == NULL) {
					cout << "Левая вершина добавлена" << endl;
					parent->Left = current;
				}
				else if (parent->Right == NULL) {
					cout << "Правая вершина добавлена" << endl;
					parent->Right = current;
				}
				else {
					cout << "Потомков более 2-ух! Вершину добавлять нельзя" << endl;
					return;
				}
			}

		}
		else {
			cout << "Родительская вершина не найдена" << endl;
			return;
		}
	}
	num++;
}

void Rev_Symmetr(LaTree* current, int level) {
	if (current != NULL) {
		level++;
		Rev_Symmetr(current->Right, level);
		for (int i = 0; i < level; i++) {
			printf("    ");
		}
		cout << current-> inf << endl;
		Rev_Symmetr(current->Left, level);
	}
}

void Delete(LaTree* &current) {
	if (current != NULL) {
		Delete(current->Left);
		Delete(current->Right);
		free(current);
		num--;
		if (num == 0) {
			current = NULL;
		}
	}
}

void main() {
	setlocale(LC_ALL, "rus");
	int select = 0;
	while (select != 5) {

		cout << "1. Добавить элемент" << endl;
		cout << "2. Поиск элемента" << endl;
		cout << "3. Вывод в обратно-симметричном порядке" << endl;
		cout << "4. Удалить дерево" << endl;
		cout << "5. Выход из программы" << endl;

		cin >> select;

		if (select == 1) {
			Add();
			system("pause");
		}
		else if (select == 2) {
			if (root != NULL) {
				cout << "Введите элемент для поиска:" << endl;
				int search;
				cin >> search;
				parent = NULL;
				stop = false;
				Search(root, search);
				if (parent != NULL) {
					cout << "Элемент найден" << endl;
				}
				else {
					cout << "Элемент не найден" << endl;
				}
			}
			else {
				cout << "Дерево пустое" << endl;
			}
			system("pause");
		}
		else if (select == 3) {
			if (root != NULL) {
				Rev_Symmetr(root, 0);
			}
			else {
				cout << "Дерево пустое" << endl;
			}
			system("pause");
		}
		else if (select == 4) {
			if (root != NULL) {
				Delete(root);
				cout << "Дерево удалено" << endl;
			} 
			else {
				cout << "Дерево пустое" << endl;
			}
			
			system("pause");
		}
		else if (select == 5) {
			break;
		}
		system("cls");
	}
}