#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>

struct LaStack {
	int value;
	LaStack* next;
};

struct LIFO {
	LaStack* sp;

	LIFO() {
		sp = NULL;
	}

	void push(int val) {
		LaStack* pTemp = new LaStack;
		pTemp->value = val;
		pTemp->next = sp;
		sp = pTemp;
	}

	void manypush() {
		int count;
		printf("Введите количество элементов\n");
		while (!scanf_s("%d", &count)) {
			while (getchar() != '\n')
				printf("Введите заново.\n");
		}
		while (count > 0) {
			push(rand());
			--count;
		}
	}

	void showstack() {
		if (sp == NULL) {
			printf("Стек пуст!\n");
			return;
		}
		printf("\n");
		LaStack* pCurrent = sp;
		while (pCurrent != NULL) {
			printf("%d\n", pCurrent->value);
			pCurrent = pCurrent->next;
		}
		printf("\n");
	}

	void pop() {
		if (sp == NULL) {
			printf("Стек пуст!\n");
			return;
		}
		LaStack* pTemp = sp;
		sp = sp->next;
		delete pTemp;
	}

	void push_ptr(LaStack* count) {
		if (count == NULL) {
			printf("Стек пуст!\n");
			return;
		}
		count->next = sp;
		sp = count;
	}

	LaStack* pop_ptr() {
		LaStack* pTemp = sp;
		if (sp != NULL)
			sp = sp->next;
		return(pTemp);
	}
};

int main()
{
	using namespace std;
	setlocale(LC_ALL, "rus");
	int select = 0;
	int value;
	LaStack* top = NULL;
	LIFO real;
	LIFO unreal;

	while (true) {
		cout << "1.Ввести элемент" << endl;
		cout << "2.Удалить элемент" << endl;
		cout << "3.Поместить элемент в вспомогательный стек" << endl;
		cout << "4.Вывести основной стек" << endl;
		cout << "5.Вывести вспомогательный стек" << endl;
		cout << "6.Выход из программы" << endl;

		while (!scanf_s("%d", &select)) {
			while (getchar() != '\n')
				cout << "Введите заново" << endl;
		}

		if (select == 1) {
			system("cls");
			cout << "1 - Ввести один элемент" << endl;
			cout << "2 - Ввести несколько элементов" << endl;

			while (!scanf_s("%d", &select)) {
				while (getchar() != '\n')
					cout << "Введите заново" << endl;
			}

			if (select == 1) {
				system("cls");
				cout << "1 - Ввести значение элемента" << endl;
				cout << "2 - Ввести элемент из вспомогательного стека" << endl;

				while (!scanf_s("%d", &select))
				{
					while (getchar() != '\n')
						cout << "Введите заново." << endl;
				}

				if (select == 1) {
					system("cls");
					printf("Введите значение: ");
					while (!scanf_s("%d", &value))
					{
						while (getchar() != '\n')
							cout << "Введите заново." << endl;
					}
					real.push(value);
					//system("pause");
				}
				else if (select == 2) {
					system("cls");
					real.push_ptr(unreal.pop_ptr());
				}
				else
				{
					cout << "Неверное значение!" << endl;
				}
			}
			else if (select == 2) {
				system("cls");
				real.manypush();
			}
			else
			{
				cout << "Неверное значение!" << endl;
			}
		}
		else if (select == 2) {
			system("cls");
			real.pop();
		}
		else if (select == 3) {
			system("cls");
			unreal.push_ptr(real.pop_ptr());
		}
		else if (select == 4) {
			system("cls");
			real.showstack();
		}
		else if (select == 5) {
			system("cls");
			unreal.showstack();
		}
		else if (select == 6) {
			system("cls");
			return 0;
		}
		system("pause");
		system("cls");
	}
	system("pause");
}
