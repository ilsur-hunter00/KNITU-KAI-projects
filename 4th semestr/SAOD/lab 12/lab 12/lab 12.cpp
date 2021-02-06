#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <iostream>

using namespace std;

struct LaTree {
	int inf;
	LaTree* Left;
	LaTree* Right;
	int count;
};

LaTree* root = NULL;
int num = 0;

int search(int inf) {
	LaTree* current = root;
	bool stop = false;
	while (current != NULL && !stop) {
		if (current->inf < inf) 
			current = current->Right;
		else if (current->inf > inf) 
			current = current->Left;
		else 
			stop = true;
	}
	if (current == NULL) 
		return 0;
	return current->count;
}

void AddRecurs(LaTree*& current, int inf) {
	if (current == NULL) {
		current = new LaTree;
		num++;
		current->inf = inf;
		current->Right = NULL;
		current->Left = NULL;
		current->count = 1;
		return;
	}
	else {
		if (current->inf < inf) {
			AddRecurs(current->Right, inf);
		}
		else {
			if (current->inf > inf) {
				AddRecurs(current->Left, inf);
			}
			else {
				current->count++;
			}
		}
	}
}

void AddNoRecurs(int inf) {
	if (root == NULL) {
		root = new LaTree;
		root->inf = inf;
		root->Right = NULL;
		root->Left = NULL;
		root->count = 1;
		num++;
		return;
	}
	else {
		LaTree* parent = root;
		LaTree* current = root;
		while (current != NULL) {
			parent = current;
			if (inf > current->inf) {
				current = current->Right;
			}
			else {
				if (inf < current->inf) {
					current = current->Left;
				}
				else {
					current->count++;
					current = NULL;
				}
			}
		}
		if (inf > parent->inf) {
			parent->Right = new LaTree;
			parent->Right->inf = inf;
			parent->Right->count = 1;
			parent->Right->Left = NULL;
			parent->Right->Right = NULL;
			num++;
		}
		else if (inf < parent->inf) {
			parent->Left = new LaTree;
			parent->Left->inf = inf;
			parent->Left->count = 1;
			parent->Left->Left = NULL;
			parent->Left->Right = NULL;
			num++;
		}
	}
}

void Rev_Symmetr(LaTree* current, int level) {
	if (current != NULL) {
		level++;
		Rev_Symmetr(current->Right, level);
		for (int i = 1; i < level; i++) {
			printf("      ");
		}
		printf("%d(%d)\n", current->inf, current->count);
		Rev_Symmetr(current->Left, level);
	}

}

void Ascending_order(LaTree* current, int level) {
	if (current != NULL) {
		level++;
		Ascending_order(current->Left, level);
		printf("%d(%d) ", current->inf, current->count);
		Ascending_order(current->Right, level);
	}
}

void Change(LaTree*& current, LaTree*& temp) {
	if (current->Right != NULL) {
		Change(current->Right, temp);
	}
	else {
		temp->inf = current->inf;
		temp = current;
		current = current->Left;
	}
}

void Delete(LaTree*& current, int inf) {
	if (current != NULL) {
		if (inf < current->inf) {
			Delete(current->Left, inf);
		}
		else if (inf > current->inf) {
			Delete(current->Right, inf);
		} 
		else {
			LaTree* temp = current;
			if (temp->Right == NULL) {
				current = temp->Left;
			}
			else if (temp->Left == NULL) {
				current = temp->Right;
			}
			else {
				Change(current->Left, temp);
			}
			free(temp);
			num--;
		}
	}
}

void Destroy(LaTree*& current) {
	if (current != NULL) {
		Destroy(current->Left);
		Destroy(current->Right);
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
	while (select != 8) {
		cout << "1. Создать дерево" << endl;
		cout << "2. Добавить рекурсивно вершину" << endl;
		cout << "3. Добавить нерекурсивно вершину" << endl;
		cout << "4. Поиск вершины" << endl;
		cout << "5. Вывод в обратно-симметричном порядке" << endl;
		cout << "6. Вывод в порядке возрастания" << endl;
		cout << "7. Удалить вершину" << endl;
		cout << "8. Уничтожить дерево" << endl;
		cout << "9. Выход из программы" << endl;

		cin >> select;
		
		if (select == 1) {
			int count;
			cout << "Введите кол-во вершин для добавления в дерево" << endl;
			cin >> count;
			for (int i = 0; i < count; i++) {
				int inf = rand() % 100 + 1;
				AddRecurs(root, inf);
			}
			system("pause");
		}
		else if (select == 2) {
			int inf;
			cout << "Введите информационную часть вершины для добавления" << endl;
			cin >> inf;
			AddRecurs(root, inf);
			system("pause");
		}
		else if (select == 3) {
			int inf;
			cout << "Введите информационную часть вершины для добавления" << endl;
			cin >> inf;
			AddNoRecurs(inf);
			system("pause");
		}
		else if (select == 4) {
			int inf;
			cout << "Введите информационную часть вершины для поиска" << endl;
			cin >> inf;
			int found = search(inf);
			if (found == NULL) {
				cout << "Элемент не найден" << endl;
				continue;
			}
			else {
				cout << "Счетчик числа появлений: " << found << endl;
			}
			system("pause");
		}
		else if (select == 5) {
			if (root != NULL) {
				Rev_Symmetr(root, 0);
			}
			else {
				cout << "Дерево пустое" << endl;
			}
			system("pause");
		}
		else if (select == 6) {
			if (root != NULL) {
				Ascending_order(root, 0);
			}
			else {
				cout << "Дерево пустое" << endl;
			}
			system("pause");
		}
		else if (select == 7) {
			if (root != NULL) {
				int inf;
				cout << "Введите информационную часть вершины для удаления" << endl;
				cin >> inf;
				Delete(root, inf);
			}
			else {
				cout << "Дерево пустое" << endl;
			}
			system("pause");
		}
		else if (select == 8) {
			Destroy(root);
			cout << "Дерево уничтожено" << endl;
			system("pause");
		}
		else if (select == 9) {
			break;
		}
		system("cls");
	}
}