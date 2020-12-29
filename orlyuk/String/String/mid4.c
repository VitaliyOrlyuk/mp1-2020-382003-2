#include "stdio.h"
#include "string.h"
#define STR_SIZE  300
#define DELIM " ,.!?:;()\t\n"

int main()
{
	char *words[100];
	int nWords = 0;
	char str[STR_SIZE] = "", *p = NULL, *pp = NULL;

	printf("Text: ");
	fgets(str, STR_SIZE, stdin);

	p = strtok_s(str, DELIM, &pp);
	while (p && nWords < 100)
	{
		words[nWords++] = p;
		p = strtok_s(NULL, DELIM, &pp);
	}

	for (int i = 0; i < nWords; i++)
	{
		int k = 0;

		for (int j = 0; j < nWords; j++)
		{
			if (j == i)
			{
				k = 1;
			}
			else if (strcmp(words[i], words[j]) == 0)
			{
				if (j < i)
					break;
				else
					k++;
			}
		}
		if (k > 0)
			printf("%-15s: %d\n", words[i], k);
	}
}