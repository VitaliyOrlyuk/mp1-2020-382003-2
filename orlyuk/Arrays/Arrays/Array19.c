#include "stdio.h"
#include "locale.h"

void main()
{
	setlocale(LC_ALL, "Russian");
	int n, i, j, k1 = 0, k2 = 0, k3 = 0, k4 = 0, k5 = 0;
	printf("������� ���������� ���������\n");
	scanf_s("%d", &n);
	int **A = (int **)malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++)
	{
		A[i] = (int *)malloc(3 * sizeof(int));
	}
	printf("���� ������\n");
	for (i = 0; i < n; i++)
	{
		printf("�������: ", i);
		for (j = 0; j < 3; j++)
			scanf_s("%d", &A[i][j]);
	}
	for(i = 0; i < n; i++)
		for (j = 0; j < 3; j++)
		{
			if (A[i][j] == 1)
				k1++;
			else if (A[i][j] == 2) 
				k2++;
			else if (A[i][j] == 3) 
				k3++;
			else if (A[i][j] == 4) 
				k4++;
			else k5++;
		}
	printf("������=%d\n", k1);
	printf("�������������������� ������=%d\n", k2);
	printf("������������������ ������=%d\n", k3);
	printf("������� ������=%d\n", k4);
	printf("�������� ������=%d\n", k5);
 
	for (int i = 0; i < n; i++)
	{
		free(A[i]);
	}
	free(A);
}