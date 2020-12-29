#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define S_MAX 300

char *brack(char *s)
{
	int level = 0;
	for (char *c = s; *c; c++)
	{
		if (*c == '(')
		{
			level++;
			if (level == 2) *c = '['; else if (level > 2) *c = '{';
		}
		else if (*c == ')')
		{
			if (level == 2) *c = ']'; else if (level > 2) *c = '}';
			level--;
			if (level < 0) return NULL;
		}
	}
	return (level == 0) ? s : NULL;
}

int main()
{
	char s[S_MAX] = "";
	printf("Text: ");
	fgets(s, S_MAX, stdin);
	char * res = brack(s);
	if (res) printf("%s\n", res); else puts("Wrong string");

}