#include"stdio.h"
#include "locale.h"
#include "stdlib.h"

void main()
{
	setlocale(LC_ALL, "Russian");
	int n, i, j;
	printf("¬ведите количество строк и стобцов");
	scanf_s("%d", &n);
	int *mas1 = (int*)malloc(n*n * sizeof(int));
	int **mas2 = (int **)malloc(n * sizeof(int *));
	for (i = 0; i < n; i++)
	{
		mas2[i] = (int *)malloc(n * sizeof(int));
	}
	for (i = 0; i < n*n; i++)
	{
		mas1[i] = 1 + i;
		printf("%3d", mas1[i]);
	}
	printf("\n\n");

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			mas2[i][j] = mas1[i*n + j];

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%3d", mas2[i][j]);
		printf("\n");
	}

	for (i = 0; i < n; i++) 
	{
		free(mas2[i]);
	}
	free(mas2);
	free(mas1);
}