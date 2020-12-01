#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include "locale.h"
#include "memory.h"
#include "string.h"
#include "time.h"
#include "windows.h"
#include "stdbool.h"

void Print(int* B, int n);
void swap2(int* B, int i)
{
	int tmp;
	tmp = B[i - 1];
	B[i - 1] = B[i];
	B[i] = tmp;
}
void swap1(int* B, int i)
{
	int tmp;
	tmp = B[i + 1];
	B[i + 1] = B[i];
	B[i] = tmp;
}
void randArray(int* B, int n, int a, int b)
{
	int i;
	for (i = 0; i < n; i++)
		B[i] = rand() % (b - a) + a;
}
void specArray(int* B, int n)
{

	printf("Введите элементы массива:\n");
	for (int i = 0; i < n; i++)
		scanf_s("%d", &B[i]);
}
void Print(int* B, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", B[i]);
	}
	printf("\n");
}
void DibBubbleSort(int *B, int n, int* nc, int* nsw)
{
	int left = 0, right = n - 1;
	int flag = 1;  // флаг наличия перемещений 
				   // Выполнение цикла пока левая граница не сомкнётся с правой и пока в массиве имеются перемещения
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++)
		{
			(*nc)++;
			if (B[i]>B[i + 1])
			{
				swap1(B, i);
				flag = 1;
				(*nsw)++;
			}
		}
		right--;
		for (int i = right; i>left; i--)
		{
			(*nc)++;
			if (B[i - 1]>B[i])
			{
				swap2(B, i);
				flag = 1;
				(*nsw)++;
			}
		}
		left++;
	}
}
void InsertSort(int *B, int n, int* nc, int* nsw)
{
	int i, j, pos;
	for (i = 1; i < n; i++)
	{
		j = B[i];
		pos = i - 1;
		(*nc)++;
		while ((pos >= 0) && (B[pos] > j))
		{
			B[pos + 1] = B[pos];
			pos = pos - 1;
			(*nsw)++;
		}
		B[pos + 1] = j;
	}
}
void Merge(int *B, int left, int mid, int right, int* nc, int* nsw)
{
	int i;
	int pos1 = left;
	int pos2 = mid + 1;
	int pos3 = 0;
	int n = right - left + 1;
	int* A = (int*)malloc(sizeof(int) * n);
	while ((pos1 <= mid) && (pos2 <= right))
	{
		(*nc)++;
		if (B[pos1] < B[pos2])
		{
			A[pos3] = B[pos1];
			pos3++;
			pos1++;
			(*nsw)++;
		}
		else
		{
			A[pos3] = B[pos2];
			pos3++;
			pos2++;
			(*nsw)++;
		}
	}
	while (pos1 <= mid)
	{
		A[pos3] = B[pos1];
		pos3++;
		pos1++;
		(*nsw)++;
	}
	while (pos2 <= right)
	{
		A[pos3] = B[pos2];
		pos2++;
		pos3++;
		(*nsw)++;
	}
	for (i = 0; i < n; i++)
		B[left + i] = A[i];
	free(A);
};
void MergeSort(int *B, int left, int right, int* nc, int* nsw)
{
	int mid;
	(*nc)++;
	if (left < right)
	{
		mid = (left + right) / 2;
		MergeSort(B, left, mid, &(*nc), &(*nsw)); //сортировка левой части
		MergeSort(B, mid + 1, right, &(*nc), &(*nsw)); //сортировка правой части
		Merge(B, left, mid, right, &(*nc), &(*nsw)); //слияние двух частей
		(*nsw);
	}
};
void Split(int *B, int left, int right, int* nc, int* nsw)
{
	int mid, i, j, tmp;
	mid = B[(right + left) / 2];
	i = left;
	j = right;
	while (i < j)
	{
		while (B[i] < mid)
		{
			i++;
		}
		while (B[j] > mid)
		{
			j--;
		}
		(*nc)++;
		if (i <= j)
		{
			tmp = B[i];
			B[i] = B[j];
			B[j] = tmp;
			i++;
			j--;
			(*nsw)++;
		}
	}
	if (left < j)
		Split(B, left, j, &(*nc), &(*nsw));
	if (i < right)
		Split(B, i, right, &(*nc), &(*nsw));
}
void spawnarray1(int** B, int n)
{
	*B = (int*)malloc(n * sizeof(int));

}
int binarysearch(int *B, int n, int key)
{
	int left = 0;
	int right = n - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (key < B[mid])
			right = mid - 1;
		else if (key > B[mid])
			left = mid + 1;
		else
			return mid;
	}
	return -1;
}
void CountingSort(int *B, int n, int* nc, int* nsw)
{
	int max = 16000;
	int* A = (int*)malloc(sizeof(int) * max);
	int currentPos = 0;
	for (int i = 0; i < max - 1; i++)
	{
		A[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		(*nc)++;
		A[B[i]]++;
		(*nsw)++;
	}

	for (int i = 0; i < max - 1; i++)
	{
		for (int j = 0; j < A[i]; j++)
		{
			B[currentPos++] = i;
		}
	}
	free(A);
}
void menu()
{
	printf("\nMENU:\n");
	printf("1. Количество элементов массива\n");
	printf("2. Ввод заданного массива\n");
	printf("3. Ввод рандомного массива\n");
	printf("4. Быстрая сортировка\n");
	printf("5. Сортировка двунаправленным пузырьком\n");
	printf("6. Сортировка вставками\n");
	printf("7. Сортировка слиянием\n");
	printf("8. Сортировка подсчетом\n");
	printf("9. Бинарный поиск\n");
	printf("0. Exit\n");
}
void main()
{
	int* B = NULL;
	int n = 0, a, b, key, nkey;
	int t = 10;
	int nComp[5];
	int nSwap[5];
	bool wasInput = false;
	LARGE_INTEGER freq, start, finish;
	double time;
	double timeAll[5];
	QueryPerformanceFrequency(&freq);
	setlocale(LC_ALL, "Russian");
	printf("start\n");
	srand(1000);

	while (t != 0)
	{
		menu();
		scanf_s("%d", &t);
		switch (t)
		{
		case 1: {
			printf("Введите количество элементов массива\n");
			scanf_s("%d", &n);
			spawnarray1(&B, n);
			wasInput = true;
			break;
		}
		case 2: {
			if (wasInput)
				specArray(B, n);
			else
				printf("Пожалуйста, введите количество элементов массива");
			break;
		}
		case 3: {
			if (wasInput)
			{
				printf("Введите наименьший элемент массива\n");
				scanf_s("%d", &a);
				printf("Введите наибольший элемент массива\n");
				scanf_s("%d", &b);
				randArray(B, n, a, b);
			}
			else
				printf("Пожалуйста, введите количество элементов массива");
			Print(B, n);
			break;
		}
		case 4: {
			if (wasInput)
			{
				int* Bcopy = (int*)malloc(sizeof(int) * n);
				memcpy(Bcopy, B, sizeof(int) * n);
				int nc = 0, nsw = 0;
				QueryPerformanceCounter(&start);
				Split(Bcopy, 0, n - 1, &nc, &nsw);
				QueryPerformanceCounter(&finish);
				time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
				timeAll[0] = time;
				Print(Bcopy, n);
				printf("Перестановки:%d\n Сравнения:%d\n", nsw, nc);
				printf("Время:%lf\n", time);
				nComp[0] = nc;
				nSwap[0] = nsw;
				free(Bcopy);
			}
			else
				printf("Ошибка, введите массив");
			break;
		}
		case 5: {
			if (wasInput)
			{
				int* Bcopy = (int*)malloc(sizeof(int) * n);
				memcpy(Bcopy, B, sizeof(int) * n);
				int nc = 0, nsw = 0;
				QueryPerformanceCounter(&start);
				DibBubbleSort(Bcopy, n, &nc, &nsw);
				QueryPerformanceCounter(&finish);
				time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
				timeAll[1] = time;
				Print(Bcopy, n);
				printf("Перестановки:%d\n Сравнения:%d\n", nsw, nc);
				printf("Время:%lf\n", time);
				nComp[1] = nc;
				nSwap[1] = nsw;
				free(Bcopy);
			}
			else
				printf("Ошибка, введите массив");
			break;
		}
		case 6: {
			if (wasInput)
			{
				int* Bcopy = (int*)malloc(sizeof(int) * n);
				memcpy(Bcopy, B, sizeof(int) * n);
				int nc = 0, nsw = 0;
				QueryPerformanceCounter(&start);
				InsertSort(Bcopy, n, &nc, &nsw);
				QueryPerformanceCounter(&finish);
				time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
				timeAll[2] = time;
				Print(Bcopy, n);
				printf("Перестановки:%d\n Сравнения:%d\n", nsw, nc);
				printf("Время:%lf\n", time);
				nComp[2] = nc;
				nSwap[2] = nsw;
				free(Bcopy);
			}
			else
				printf("Ошибка, введите массив");
			break;
		}
		case 7: {
			if (wasInput)
			{
				int* Bcopy = (int*)malloc(sizeof(int) * n);
				memcpy(Bcopy, B, sizeof(int) * n);
				int nc = 0, nsw = 0;
				QueryPerformanceCounter(&start);
				MergeSort(Bcopy, 0, n - 1, &nc, &nsw);
				QueryPerformanceCounter(&finish);
				time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
				timeAll[3] = time;
				Print(Bcopy, n);
				printf("Перестановки:%d\n Сравнения:%d\n", nsw, nc);
				printf("Время:%lf\n", time);
				nComp[3] = nc;
				nSwap[3] = nsw;
				free(Bcopy);
			}
			else
				printf("Ошибка, введите массив");
			break;
		}
		case 8: {
			if (wasInput)
			{
				int* Bcopy = (int*)malloc(sizeof(int) * n);
				memcpy(Bcopy, B, sizeof(int) * n);
				int nc = 0, nsw = 0;
				QueryPerformanceCounter(&start);
				CountingSort(Bcopy, n, &nc, &nsw);
				QueryPerformanceCounter(&finish);
				time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
				timeAll[4] = time;
				Print(Bcopy, n);
				printf("Перестановки:%d\n Сравнения:%d\n", nsw, nc);
				printf("Время:%lf\n", time);
				nComp[4] = nc;
				nSwap[4] = nsw;
				free(Bcopy);
			}
			else
				printf("Ошибка, введите массив");
			break;
		}
		case 9: {
			if (wasInput)
			{
				int* Bcopy = (int*)malloc(sizeof(int) * n);
				memcpy(Bcopy, B, sizeof(int) * n);
				Print(Bcopy, n);
				printf("Введите элементы: \n");
				scanf_s("%d", &key);
				nkey = binarysearch(Bcopy, n, key);
				if (nkey != -1)
					printf("Количество элементов: %d\n", nkey);
				else
					printf("Элементы не найдены\n");
				free(Bcopy);
			}
			break;
		}
		case 0: {
			break;
		}
				break;
		}
	}
	free(B);
}