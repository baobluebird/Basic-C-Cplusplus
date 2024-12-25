#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	char c;
	while ((c = getchar()) != EOF)
		putchar(c);
}
