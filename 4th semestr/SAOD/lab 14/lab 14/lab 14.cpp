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

void Shell(int array[], int size) {
	int count1 = 0;
	int count2 = 0;
	int* arr = new int[size + 1];
	for (int i = 0; i <= size; i++) {
		arr[i] = array[i];
	}

	int steps = round(log2f(size+1)) - 1;

	for (int m = steps; m >= 1; m--) {
		int k = pow(2, m) - 1;
		for (int i = k; i <= size - 1; i++) {
			int temp = arr[i];
			int j = i - k;
			while (j>=0 && temp < arr[j]) {
				count2++;
				count1++;
				arr[j + k] = arr[j];
				j = j - k;
			}
			count1++;
			arr[j + k] = temp;
		}

	}
	cout << "" << endl;
	cout << "СОРТИРОВКА	ШЕЛЛА: " << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "" << endl;
	cout << "Количество сравнений: " << count1 << endl;
	cout << "Количество перестановок: " << count2 << endl;
	cout << endl;
}

int pyr_count1 = 0;
int pyr_count2 = 0;

void Sito(int arr[], int alef, int arigh) {
	int i, j, x;
	i = alef;
	j = 2 * alef;
	x = arr[alef];
	pyr_count1++;
	if (j < arigh && arr[j + 1] > arr[j]) {
		++j;
	}
	pyr_count1++;
	while (j <= arigh && arr[j] > x) {
		++pyr_count2;
		arr[i] = arr[j];
		i = j;
		j = 2 * j;
		pyr_count1++;
		if (j < arigh && arr[j + 1] > arr[j]) {
			pyr_count1++;
			j++;
		}
	}
	arr[i] = x;
}

void Pyramid(int array[], int size) {

	int* arr = new int[size + 2];
	arr[0] = NULL;
	for (int i = 0; i <= size; i++) {
		arr[i + 1] = array[i];
	}

	int left = size / 2 + 1;
	int right = size + 1;
	while (left > 1) {
		left--;
		Sito(arr, left, right);
	}
	int temp;
	while (right > 1) {
		pyr_count2++;
		temp = arr[1];
		arr[1] = arr[right];
		arr[right] = temp;
		right--;
		Sito(arr, left, right);
	}

	cout << "" << endl;
	cout << "ПИРАМИДАЛЬНАЯ СОРТИРОВКА: " << endl;
	for (int i = 0; i <= size; i++) {
		cout << arr[i] << " ";
	}
	cout << "" << endl;
	cout << "Количество сравнений: " << pyr_count1 << endl;
	cout << "Количество перестановок: " << pyr_count2 << endl;
	cout << endl;
}

int countQ1 = 0;
int countQ2 = 0;

void Quicksort(int arr[], int left, int right) {
	int i, j, med, temp;
	i = left;
	j = right;
	med = arr[(left + right) / 2];
	do {
		while (arr[i] < med) {
			countQ1++;
			i++;
		}
		while (arr[j] > med) {
			countQ1++;
			j--;
		}
		if (i <= j) {
			countQ2++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j) {
		Quicksort(arr, left, j);
	}
	if (i < right) {
		Quicksort(arr, i, right);
	}
}

void Quick(int a[], int size) {
	int* arr = new int[size + 1];
	for (int i = 0; i <= size; i++) {
		arr[i] = a[i];
	}
	Quicksort(arr, 0, size);
	cout << "" << endl;
	cout << "БЫСТРАЯ СОРТИРОВКА:" << endl;;
	for (int i = 0; i <= size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Количество сравнений: " << countQ1 << endl;
	cout << "Количество перестановок: " << countQ2 << endl;
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

	while (select != 8) {

		cout << "1. Выбрать массив" << endl;
		cout << "2. Сортировка обменом" << endl;
		cout << "3. Сортировка вставками" << endl;
		cout << "4. Сортировка выбором" << endl;
		cout << "5. Метод Шелла" << endl;
		cout << "6. Быстрая сортировка" << endl;
		cout << "7. Пирамидальная сортировка" << endl;
		cout << "8. Выход из программы" << endl;
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
			Shell(arr, size);
		}
		else if (select == 6) {
			Quick(arr, size);
		}
		else if (select == 7) {
			Pyramid(arr, size);
		}
		else if (select == 8) {
			break;
		}
	}
}