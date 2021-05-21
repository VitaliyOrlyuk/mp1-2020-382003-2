#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include "locale.h"
#include "memory.h"
#include "string.h"
#include "time.h"
#include "windows.h"
#include "stdbool.h"
#include "sorts.h"

void menu()
{
	printf("\nMENU:\n");
	printf("1. ���������� ��������� �������\n");
	printf("2. ���� ��������� �������\n");
	printf("3. ���� ���������� �������\n");
	printf("4. ������� ����������\n");
	printf("5. ���������� ��������������� ���������\n");
	printf("6. ���������� ���������\n");
	printf("7. ���������� ��������\n");
	printf("8. ���������� ���������\n");
	printf("9. �������� �����\n");
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
			printf("������� ���������� ��������� �������\n");
			scanf_s("%d", &n);
			spawnarray1(&B, n);
			wasInput = true;
			break;
		}
		case 2: {
			if (wasInput)
				specArray(B, n);
			else
				printf("����������, ������� ���������� ��������� �������");
			break;
		}
		case 3: {
			if (wasInput)
			{
				printf("������� ���������� ������� �������\n");
				scanf_s("%d", &a);
				printf("������� ���������� ������� �������\n");
				scanf_s("%d", &b);
				randArray(B, n, a, b);
			}
			else
				printf("����������, ������� ���������� ��������� �������");
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
				printf("������������:%d\n ���������:%d\n", nsw, nc);
				printf("�����:%lf\n", time);
				nComp[0] = nc;
				nSwap[0] = nsw;
				free(Bcopy);
			}
			else
				printf("������, ������� ������");
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
				printf("������������:%d\n ���������:%d\n", nsw, nc);
				printf("�����:%lf\n", time);
				nComp[1] = nc;
				nSwap[1] = nsw;
				free(Bcopy);
			}
			else
				printf("������, ������� ������");
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
				printf("������������:%d\n ���������:%d\n", nsw, nc);
				printf("�����:%lf\n", time);
				nComp[2] = nc;
				nSwap[2] = nsw;
				free(Bcopy);
			}
			else
				printf("������, ������� ������");
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
				printf("������������:%d\n ���������:%d\n", nsw, nc);
				printf("�����:%lf\n", time);
				nComp[3] = nc;
				nSwap[3] = nsw;
				free(Bcopy);
			}
			else
				printf("������, ������� ������");
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
				printf("������������:%d\n ���������:%d\n", nsw, nc);
				printf("�����:%lf\n", time);
				nComp[4] = nc;
				nSwap[4] = nsw;
				free(Bcopy);
			}
			else
				printf("������, ������� ������");
			break;
		}
		case 9: {
			if (wasInput)
			{
				int* Bcopy = (int*)malloc(sizeof(int) * n);
				memcpy(Bcopy, B, sizeof(int) * n);
				Print(Bcopy, n);
				printf("������� ��������: \n");
				scanf_s("%d", &key);
				nkey = binarysearch(Bcopy, n, key);
				if (nkey != -1)
					printf("���������� ���������: %d\n", nkey);
				else
					printf("�������� �� �������\n");
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