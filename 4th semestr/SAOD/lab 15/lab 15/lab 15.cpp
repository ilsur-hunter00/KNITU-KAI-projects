#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>
#include <iostream>

using namespace std;

void Show(int* mass, int size) {
	for (int i = 0; i < size; i++) {
		cout << mass[i] << " ";
	}
}

void PocketSortWithMassive(int* mass, int size) {
	int* mass2 = (int*)malloc(size * sizeof(int));
	int count2 = 0;
	for (int i = 0; i < size; i++) {
		mass2[mass[i]] = mass[i];
		count2++;
	}
	cout << "" << endl;
	cout << "Отсортированный массив: " << endl;
	cout << "" << endl;
	Show(mass2, size);
	cout << "" << endl;
	cout << "КАРМАННАЯ СОРТИРОВКА С ВСПОМОГАТЕЛЬНЫМ МАССИВОМ" << endl;
	cout << "Сравнений: 0" << endl;
	cout << "Перестановок: " << count2 << endl;
}

void PocketSortWithoutMass(int* mass, int size) {
	int* m = (int*)malloc(size * sizeof(int));
	memcpy(m, mass, size * sizeof(int));
	unsigned long count1 = 0, count2 = 0;
	for (int i = 0; i < size; i++) {
		count1++;
		while (m[i] != i) {
			count1++;
			int temp = m[i];
			m[i] = m[temp];
			m[temp] = temp;
			count2++;
		}
	}
	cout << "" << endl;
	cout << "Отсортированный массив: " << endl;
	cout << "" << endl;
	Show(m, size);
	cout << "" << endl;
	cout << "КАРМАННАЯ СОРТИРОВКА БЕЗ ВСПОМОГАТЕЛЬНОГО МАССИВА" << endl;
	cout << "Сравнений: " << count1 << endl;
	cout << "Перестановок: " << count2 << endl;
}

struct LaList {
	int inf;
	LaList* next;
	LaList* left;
};

struct Array {
	LaList* el;
	LaList* last;
};

void PocketSort(int* mass, int size) {
	int* m = (int*)malloc(size * sizeof(int));
	memcpy(m, mass, size * sizeof(int));
	unsigned long count2 = 0, count1 = 0;
	Array* result = (Array*)malloc(size * (sizeof(Array)));
	for (int i = 0; i < size; i++) {
		result[i].el = NULL;
	}
	for (int i = 0; i < size; i++) {
		LaList* next = result[m[i]].el;
		result[m[i]].el = (LaList*)malloc(sizeof(LaList));
		result[m[i]].el->next = next;
		result[m[i]].el->inf = m[i];
	}
	for (int i = 0, j = 0; i < size; i++, count1++) {
		while (result[i].el != NULL) {
			count1++;
			count2++;
			m[j] = result[i].el->inf;
			j++;
			result[i].el = result[i].el->next;
		}
	}
	cout << "" << endl;
	cout << "Отсортированный массив: " << endl;
	cout << "" << endl;
	Show(m, size);
	cout << "" << endl;
	cout << "ОБОБЩЕННАЯ КАРМАННАЯ СОРТИРОВКА" << endl;
	cout << "Сравнений: " << count1 << endl;
	cout << "Перестановок: " << count2 << endl;
}

void RadixSort(int* mass, int size) {
	int* m = (int*)malloc(size * sizeof(int));
	memcpy(m, mass, size * sizeof(int));
	unsigned long count2 = 0;
	Array* result = (Array*)malloc(10 * (sizeof(Array)));
	for (int bitwise = 1; bitwise < 1000; bitwise = bitwise * 10) {
		for (int i = 0; i < 10; i++) {
			result[i].el = NULL;
			result[i].last = NULL;
		}
		for (int i = 0; i < size; i++) {
			
			int index = (m[i] % (10 * bitwise)) / bitwise;
			LaList* next = result[index].el;
			result[index].el = (LaList*)malloc(sizeof(LaList));
			result[index].el->next = next;
			result[index].el->left = NULL;
			result[index].el->inf = m[i];
			if (next != NULL) {
				next->left = result[index].el;
			}
			else {
				result[index].last = result[index].el;
			}
		}
		for (int i = 0, j = 0; i < 10; i++) {
			while (result[i].last != NULL && j < size) {
				
				count2++;
				m[j] = result[i].last->inf;
				result[i].last = result[i].last->left;
				j++;
			}
		}
	}
	cout << "" << endl;
	cout << "Отсортированный массив: " << endl;
	cout << "" << endl;
	Show(m, size);
	cout << "" << endl;
	cout << "ПОРАЗРЯДНАЯ СОРТИРОВКА" << endl;
	cout << "Сравнений: 0" << endl;
	cout << "Перестановок: " << count2 << endl;
}

void main() {
	setlocale(LC_ALL, "rus");
	int size;
	cout << "Введите размер массива: " << endl;
	cin >> size;
	int* mass = (int*)malloc(size * sizeof(int));
	int select = 0;

	

	while (select != 5) {
		cout << "1. Карманная сортировка с вспомогательным массивом" << endl;
		cout << "2. Карманная сортировка без вспомогательного массива" << endl;
		cout << "3. Обобщенная карманная сортировка" << endl;
		cout << "4. Поразрядная сортировка" << endl;
		cout << "5. Выход из программы" << endl;

		cout << "" << endl;
		cin >> select;
		if (select == 1) {
			int i = 0;
			int a;
			while (i < size) {
				a = rand() % size;
				for (int j = i; j >= 0; j--) {
					if (mass[j] == a) {
						break;
					}
					else if (j == 0) {
						mass[i] = a;
						i++;
					}
				}
			}
			cout << "Исходный массив: " << endl;
			cout << "" << endl;
			Show(mass, size);
			PocketSortWithMassive(mass, size);
		}
		else if (select == 2) {
			int i = 0;
			int a;
			while (i < size) {
				a = rand() % size;
				for (int j = i; j >= 0; j--) {
					if (mass[j] == a) {
						break;
					}
					else if (j == 0) {
						mass[i] = a;
						i++;
					}
				}
			}
			cout << "Исходный массив: " << endl;
			cout << "" << endl;
			Show(mass, size);
			PocketSortWithoutMass(mass, size);
		}
		else if (select == 3) {
			cout << "Исходный массив: " << endl;
			cout << "" << endl;
			for (int i = 0; i < size; i++) {
				mass[i] = rand() % size;
				cout << mass[i] << " ";
			}
			cout << "" << endl;
			PocketSort(mass, size);
		}
		else if (select == 4) {
			cout << "Исходный массив: " << endl;
			cout << "" << endl;
			for (int i = 0; i < size; i++) {
				mass[i] = rand() % 900 + 100;
				cout << mass[i] << " ";
			}
			cout << "" << endl;
			RadixSort(mass, size);
		}
		else if (select == 5) {
			break;
		}
	}
}