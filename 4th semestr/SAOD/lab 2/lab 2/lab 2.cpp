#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>

using namespace std;

struct FIFO {
	int* array;
	int First;
	int Last;
	int c;
	int len;

	FIFO(int length) {
		len = length;
		array = new int[len];
		c = 0;
		First = 0;
		Last = 0;
	}

	void push() {
		if (c == len) {
			cout << "Очередь полна!" << endl;
			return;
		}
		int val;
		cout << "Введите число: " << endl;
		while (!scanf_s("%d", &val)) {
			while (getchar() != '\n')
				printf("Введите число: \n");
		}
		array[Last] = val;
		++c;
		++Last;
		Last = (Last == len) ? 0 : Last;
	}

	void show() {
		if (c == 0) {
			cout << "Очередь пуста!" << endl;
			return;
		}
		cout << "Очередь: " << endl;
		int current = First;
		for (int i = 0; i < c; i++) {
			printf("%d\n", array[current]);
			++current;
			current = (current == len) ? 0 : current;
		}
	}

	void pop() {
		if (c == 0) {
			cout << "Очередь пуста!" << endl;
			return;
		}
		array[First] = NULL;
		--c;
		++First;
		First = (First == len) ? 0 : First;
	}
};

int main() {
	setlocale(LC_ALL, "rus");
	int select = 0;
	int value;
	cout << "Введите длину очереди: " << endl;
	while (!scanf_s("%d", &value)) {
		while (getchar() != '\n')
			cout << "Введите число: " << endl;
	}
	FIFO queue = FIFO(value);

	while (true) {
		cout << "1.Ввести элемент" << endl;
		cout << "2.Удалить элемент" << endl;
		cout << "3.Показать очередь" << endl;
		cout << "4.Выход из программы" << endl;
		while (!scanf_s("%d", &select)) {
			while (getchar() != '\n')
				printf("Введите снова\n");
		}
		if (select == 1) {
			system("cls");
			queue.push();
		}
		else if (select == 2) {
			system("cls");
			queue.pop();
		}
		else if (select == 3) {
			system("cls");
			queue.show();
		}
		else if (select == 4) {
			return 0;
		}
	}
}