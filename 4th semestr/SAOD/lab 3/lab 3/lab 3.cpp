#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string>

using namespace std;

struct LaQueue {
	int value;
	LaQueue* next;
};

struct FIFO {
	LaQueue* sp;
	FIFO() {
		sp = NULL;
	}
	
	void push(int val) {
		LaQueue* pTemp = new LaQueue;
		pTemp->value = val;
		pTemp->next = NULL;
		if (sp == NULL) {
			sp = pTemp;
		}
		else {
			LaQueue* cur = sp;
			while (cur->next != NULL)
				cur = cur->next;
			cur->next = pTemp;
		}
	}

	void pop() {
		if (sp == NULL) {
			cout << "Очередь пуста! " << endl;
			return;
		}
		LaQueue* pTemp = sp;
		sp = sp->next;
		delete pTemp;
	}

	void show() {
		cout << endl << "Очередь: " << endl;
		if (sp == NULL) {
			cout << "Очередь пуста!" << endl;
			return;
		}
		LaQueue* pCurrent = sp;
		while (pCurrent != NULL) {
			cout << pCurrent->value << endl;
			pCurrent = pCurrent->next;
		}
	}

};

int main() {
	setlocale(LC_ALL, "rus");
	FIFO q;
	time_t Ttime;
	char exit = 27;
	int action;
	int c;
	char wrt;
	string LaStr;
	string Ending;
	while (!(_kbhit() && _getch() == exit)) {
		action = 1 + (rand() % 100);
		c = 1 + (rand() % 3);
		LaStr = (c == 1) ? "Элемента" : "Элементов";
		Ending = (c == 1) ? "-го" : "-х";
		if (action % 2 == 0) {
			cout << endl << "Добавление" << " " << c << Ending << " " << LaStr << endl;
			for (int i = 0; i < c; i++) {
				wrt = 65 + (rand() % 26);
				q.push(wrt);
			}
		}
		else {
			cout << endl << "Удаление" << " " << c << Ending << " " << LaStr << endl;
			for (int i = 0; i < c; i++) {
				q.pop();
			}
		}
		q.show();
		Ttime = time(NULL);
		while (time(NULL) - Ttime < 3) {
			if (_kbhit()) {
				if (_getch() == exit)
					return 0;
				else
					break;
			}

		}
	}
	return 0;
}