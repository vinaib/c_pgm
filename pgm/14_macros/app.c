#include<stdio.h>

/* Converts to boolean */
#define BB(x) (!!x)
int main(void)
{
	int i = 10;

	printf("%d %d\n", i, BB(i));
}
