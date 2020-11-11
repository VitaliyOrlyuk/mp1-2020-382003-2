#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
void Print(int B[], int n);
void swap(int B[], int i)
{
	int tmp;
	tmp = B[i];
	B[i] = B[i - 1];
	B[i - 1] = tmp;
}
void randArray(int B[], int n, int a, int b)
{
	int i;
	for (i = 0; i < n; i++)
		B[i] = rand() % (b - a) + a;
}
void Print(int B[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", B[i]);
	printf("\n");
}
void DibBubbleSort(int B[],  int n)
{
	int leftmark = 1;
	int rightmark = n - 1;
	while (leftmark <= rightmark)
	{
		for (int i = rightmark; i >= leftmark; i--)
			if (B[i - 1] > B[i]) swap(B, i);
		leftmark++;

		for (int i = leftmark; i <= rightmark; i++)
			if (B[i - 1] > B[i]) swap(B, i);
		rightmark--;
	
	}

}
void InsertSort(int B[], int n)
{
	int i, x, pos;
	for (i = 1; i < n; i++)
	{
		x = B[i];
		pos = i - 1;
		while ((pos >= 1) && (B[pos] > x))
		{
			B[pos + 1] = B[pos];
			pos = pos - 1;
		}
		B[pos + 1] = x;
	}
}
void Merge(int *B, int left, int right)
{
	int mid, pos1, pos2, i, *A;
	A = (int*)malloc(sizeof(int)*10);
	mid = (left + right) / 2;
	pos1 = left; //начало левой части
	pos2 = mid + 1; //начало правой части
	for (i = left; i <= right; i++) 
		if ((pos1 <= mid) && ((pos2>right) || (B[pos1]<B[pos2])))
		{
			A[i] = B[pos1];
			pos1++;
		}
		else
		{
			A[i] = B[pos2];
			pos2++;
		}
	for (i = left; i <= right; i++) B[i] = A[i];
	free(A);
};

void MergeSort(int *B, int left, int right)
{
	{
		if (left < right)
		{
			MergeSort(B, left, (left + right)/2); //сортировка левой части
			MergeSort(B, (left+right)/2 + 1, right); //сортировка правой части
			Merge(B, left, right); //слияние двух частей
		}
	}
};
void menu()
{
	printf("\nMENU:\n");
	printf("1. Input array\n");
	printf("2. Print array\n");
	printf("3. DibBubbleSort\n");
	printf("4. InsertSort\n");
	printf("5. MergeSort\n");
	printf("0. Exit\n");
}
void main()
{
	int B[10];
	int n = 10;
	int t = 10;

	printf("start\n");
	srand(1000);

	while (t != 0)
	{
		menu();
		scanf_s("%d", &t);
		switch (t)
		{
		case 1: {
			//sortedArray(B, n);
			randArray(B, n, -10, 10);
			break;
		}
		case 2: {
			Print(B, n);
			break;
		}
		case 3: {
			DibBubbleSort(B, n);
			Print(B, n);
		}
		case 4: {
			InsertSort(B, n);
			Print(B, n);
		}
		case 5:{
			MergeSort(B, 0, n);
				Print(B, n);
		}
			   break;
		}
	}
}