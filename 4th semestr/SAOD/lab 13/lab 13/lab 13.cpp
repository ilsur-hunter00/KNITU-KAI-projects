#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

void Create(int array[], int size) {
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 10000;
	}
}

void Bubble(int array[], int size) {
	int count1 = 0;
	int count2 = 0;
	int* arr = new int[size + 1];
	for (int i = 0; i <= size; i++) {
		arr[i] = array[i];
	}
	for (int i = 1; i <= size; i++) {
		for (int j = size; j >= i; j--) {
			count1++;
			if (arr[j] < arr[j - 1]) {
				count2++;
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	cout << "" << endl;
	cout << "СОРТИРОВКА ОБМЕНОМ: " << endl;
	for (int i = 0; i <= size; i++) {
		cout << arr[i] << " ";
	}
	cout << "" << endl;
	cout << "Количество сравнений: " << count1 << endl;
	cout << "Количество перестановок: " << count2 << endl;
	cout << endl;
}

void Insert(int array[], int size) {
	int count1 = 0;
	int count2 = 0;
	int* arr = new int[size + 1];
	for (int i = 0; i <= size; i++) {
		arr[i] = array[i];
	}
	for (int i = 1; i <= size; i++) {
		int temp = arr[i];
		int j = i - 1;
		while (j >= 0 && temp < arr[j]) {
			count1++;
			count2++;
			arr[j + 1] = arr[j];
			j--;
		}
		count1++;
		arr[j + 1] = temp;
	}
	cout << "" << endl;
	cout << "СОРТИРОВКА ВСТАВКАМИ: " << endl;
	for (int i = 0; i <= size; i++) {
		cout << arr[i] << " ";
	}
	cout << "" << endl;
	cout << "Количество сравнений: " << count1 << endl;
	cout << "Количество перестановок: " << count2 << endl;
	cout << endl;
}

void Choice(int array[], int size) {
	int count1 = 0;
	int count2 = 0;
	int* arr = new int[size + 1];
	for (int i = 0; i <= size; i++) {
		arr[i] = array[i];
	}
	for (int i = 0; i <= size - 1; i++) {
		int k = i;
		int temp = arr[i];
		for (int j = i + 1; j <= size; j++) {
			count1++;
			if (arr[j] < temp) {
				k = j;
				temp = arr[j];
			}
		}
		if (arr[i] != temp) {
			count2++;
		}
		arr[k] = arr[i];
		arr[i] = temp;
	}
	cout << "" << endl;
	cout << "СОРТИРОВКА	ВЫБОРОМ: " << endl;
	for (int i = 0; i <= size; i++) {
		cout << arr[i] << " ";
	}
	cout << "" << endl;
	cout << "Количество сравнений: " << count1 << endl;
	cout << "Количество перестановок: " << count2 << endl;
	cout << endl;
}


void main() {
	setlocale(LC_ALL, "rus");
	const int siz1 = 10;
	const int siz2 = 100;
	const int siz3 = 1000;

	int array_1[siz1];
	int array_2[siz2];
	int array_3[siz3];

	Create(array_1, siz1);
	Create(array_2, siz2);
	Create(array_3, siz3);

	int* arr = array_1;
	int size = siz1 - 1;
	int select = 0;

	while (select != 5) {

		cout << "1. Выбрать массив" << endl;
		cout << "2. Сортировка обменом" << endl;
		cout << "3. Сортировка вставками" << endl;
		cout << "4. Сортировка выбором" << endl;
		cout << "5. Выход из программы" << endl;
		cout << "" << endl;
		cin >> select;
		cout << "" << endl;
		
		if (select == 1) {
			int flag = 1;
			int select_1;
			while (flag) {
				cout << "1. Выбрать массив из 10 элементов" << endl;
				cout << "2. Выбрать массив из 100 элементов" << endl;
				cout << "3. Выбрать массив из 1000 элементов" << endl;
				cout << "" << endl;
				cin >> select_1;
				cout << "" << endl;
				if (select_1 >= 1 && select_1 <= 3) {
					flag = 0;
				}
			}
			if (select_1 == 1) {
				arr = array_1;
				size = siz1 - 1;
			}
			else if (select_1 == 2) {
				arr = array_2;
				size = siz2 - 1;
			}
			else if (select_1 == 3) {
				arr = array_3;
				size = siz3 - 1;
			}
		}
		else if (select == 2) {
			Bubble(arr, size);
		}
		else if (select == 3) {
			Insert(arr, size);
		}
		else if (select == 4) {
			Choice(arr, size);
		}
		else if (select == 5) {
			break;
		}
	}
}