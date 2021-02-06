#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <iostream>
 
using namespace std;

struct SubList {
	int subinform;
	SubList* next;
};

struct MainList {
	int maininform;
	MainList* NextMain;
	SubList* Firstsub;
};

struct ListList {
	MainList* list;

	ListList() {
		list = new MainList;
		list->NextMain = NULL;
		list->Firstsub = NULL;
	}

	void Show() {
		MainList* temp = list;
		cout << "Главный список | Вспомогательный список" << endl;
		if (temp->NextMain == NULL) {
			cout << "Список пуст!" << endl;
		}
		while (temp->NextMain != NULL) {
			temp = temp->NextMain;
			printf("%d             |", temp->maininform);
			SubList* subl = temp->Firstsub;
			while (subl != NULL) {
				printf(" %d ", subl->subinform);
				subl = subl->next;
			}
			cout << "" << endl;
		}
	}

	void pushStart() {
		system("cls");
		cout << "Введите новый элемент" << endl;
		int newEl;
		cin >> newEl;
		MainList* ptemp = new MainList;
		ptemp->maininform = newEl;
		ptemp->NextMain = NULL;
		ptemp->Firstsub = NULL;
		list->NextMain = ptemp;
		cout << "Элемент добавлен!" << endl;
	}
	void pushAfter() {
		if (list->NextMain == NULL) {
			pushStart();
		}
		else {
			int prev;
			cout << "Введите значение предшествующего элемента" << endl;
			cin >> prev;
			MainList* temp = list->NextMain;
			while (temp != NULL) {
				if (temp->maininform == prev) {
					int newEl;
					cout << "Значение нового элемента: " << endl;
					cin >> newEl;
					MainList* pTemp = new MainList;
					pTemp->maininform = newEl;
					pTemp->Firstsub = NULL;
					pTemp->NextMain = temp->NextMain;
					temp->NextMain = pTemp;
					cout << "Элемент добавлен!" << endl;
				}
				temp = temp->NextMain;
			}
		}
	}

	void pushBefore() {
		if (list->NextMain == NULL) {
			pushStart();
		}
		else {
			int aft;
			cout << "Введите значение последующего элемента" << endl;
			cin >> aft;
			MainList* last = list;
			MainList* temp = list->NextMain;
			while (temp != NULL) {
				if (temp->maininform == aft) {
					int newEl;
					cout << "Значение нового элемента: " << endl;
					cin >> newEl;
					MainList* ptemp = new MainList;
					ptemp->maininform = newEl;
					ptemp->Firstsub = NULL;
					ptemp->NextMain = temp;
					last->NextMain = ptemp;
					cout << "Элемент добавлен!" << endl;
					return;
				}
				last = last->NextMain;
				temp = temp->NextMain;
			}
		}
	}

	void AddToList() {
		if (list == NULL) {
			cout << "Основной список пуст" << endl;
			return;
		}
		int mainEl;
		cout << "Введите элемент главного списка, к которому хотите добавить вспомогательный" << endl;
		cin >> mainEl;
		MainList* temp = list;
		while (temp != NULL) {
			if (temp->maininform == mainEl) {
				if (temp->Firstsub == NULL) {
					int AddEl;
					cout << "Введите значение добавляемого элемента:" << endl;
					cin >> AddEl;
					SubList* subl = new SubList;
					subl->subinform = AddEl;
					subl->next = NULL;
					temp->Firstsub = subl;
					return;
				}
				int ask;
				int aft;
				cout << "1. Добавить элемент до заданного" << endl;
				cout << "2. Добавить элемент после заданного" << endl;
				cin >> ask;
				SubList* subl = temp->Firstsub;
				if (ask == 1) {
					cout << "Введите значение последующего элемента" << endl;
					cin >> aft;
					cout << "Введите добавляемый элемент" << endl;
					int value;
					cin >> value;
					if (subl->subinform == aft) {
						SubList* sub2 = new SubList;
						sub2->subinform = value;
						sub2->next = temp->Firstsub;
						temp->Firstsub = sub2;
						return;
					}
					while (subl->next != NULL) {
						if (subl->next->subinform == aft) {
							SubList* sub2 = new SubList;
							sub2->subinform = value;
							sub2->next = subl->next;
							subl->next = sub2;
							return;
						}
						subl = subl->next;
					}
				}
				else if (ask == 2) {
					cout << "Введите значение предшествующего элемента" << endl;
					cin >> aft;
					cout << "Введите добавляемый элемент.( добавляется в вспомогательный список)" << endl;
					int value;
					cin >> value;
					while (subl != NULL) {
						if (subl->subinform == aft) {
							SubList* sub2 = new SubList;
							sub2->subinform = value;
							sub2->next = subl->next;
							subl->next = sub2;
							return;
						}
						subl = subl->next;
					}
				}
			}
			temp = temp->NextMain;
		}
	}

	void DeleteMain() {
		if (list == NULL) {
			cout << "Список пуст!" << endl;
			return;
		}
		int delet;
		cout << "Введите значение удаляемого элемента" << endl;
		cin >> delet;
		MainList* temp = list;
		if (temp->maininform == delet) {
			MainList* del = list;
			list = list->NextMain;
			SubList* del2 = temp->Firstsub;
			while (del2 != NULL) {
				SubList* del1 = del2;
				del2 = del2->next;
				free(del1);
			}
			return;
		}
		while (temp->NextMain != NULL) {
			if (temp->NextMain->maininform == delet) {
				MainList* del = temp->NextMain;
				temp->NextMain = del->NextMain;
				free(del->Firstsub);
				free(del);
				return;
			}
			temp = temp->NextMain;
		}
	}

	void DeleteSub() {
		int delet;
		int delM;
		cout << "Введите элемент основного списка, в котором хотите удалить элемент вспомогательного" << endl;
		cin >> delM;
		MainList* temp = list;
		while (temp != NULL) {
			if (temp->maininform == delM) {
				if (temp->Firstsub == NULL) {
					cout << "Список пуст!" << endl;
					return;
				}
				cout << "Введите значение удаляемого элемента" << endl;
				cin >> delet;
				SubList* subl = temp->Firstsub;
				if (subl->subinform == delet) {
					SubList* del = temp->Firstsub;
					temp->Firstsub = temp->Firstsub->next;
					free(del);
					return;
				}
				while (subl->next != NULL) {
					if (subl->next->subinform == delet) {
						SubList* del = subl->next;
						subl->next = del->next;
						free(del);
						return;
					}
					subl = subl->next;
				}
			}
			temp = temp->NextMain;
		}
	}

	void Search() {
		if (list == NULL) {
			cout << "Список пуст!" << endl;
			return;
		}
		int search;
		int k = 0;
		cout << "Введите значение для поиска: " << endl;
		cin >> search;
		MainList* temp = list;
		while (temp != NULL) {
			SubList* subl = temp->Firstsub;
			if (temp->maininform == search) {
				cout << "Элемент найден в главном списке" << endl;
				k++;
			}
			if (subl == NULL) {
				temp = temp->NextMain;
				continue;
			}
			while (subl != NULL) {
				if (subl->subinform == search) {
					cout << "Элемент найден в вспомогательном списке" << endl;
					k++;
				}
				subl = subl->next;
			}
			temp = temp->NextMain;
		}
		if (k == 0) {
			cout << "Элемент не найден" << endl;
		}
	}
};

void main() {
	setlocale(LC_ALL, "rus");
	int select = 0;
	ListList list;
	while (select != 7) {
		cout << "1. Добавить элемент в главный список" << endl;
		cout << "2. Добавить элемент в вспомогательный списо" << endl;
		cout << "3. Удалить элемент из главного списка" << endl;
		cout << "4. Удалить элемент из вспомогательного списка" << endl;
		cout << "5. Поиск элемента" << endl;
		cout << "6. Вывод структуры" << endl;
		cout << "7. Выход из программы" << endl;

		cin >> select;
		
		system("cls");
		if (select == 1) {
			int variant;
			cout << "1. Добавить до заданного элемента" << endl;
			cout << "2. Добавить  после заданного элемента" << endl;
			cin >> variant;
			if (variant == 1) {
				list.pushBefore();
			}
			else if (variant == 2) {
				list.pushAfter();
			}
			system("pause");
		}
		else if (select == 2) {
			list.AddToList();
			system("pause");
		}
		else if (select == 3) {
			list.DeleteMain();
			system("pause");
		}
		else if (select == 4) {
			list.DeleteSub();
			system("pause");
		}
		else if (select == 5) {
			list.Search();
			system("pause");
		}
		else if (select == 6) {
			list.Show();
			system("pause");
		}
		else if (select == 7) {
			break;
		}
		system("cls");
	}
}