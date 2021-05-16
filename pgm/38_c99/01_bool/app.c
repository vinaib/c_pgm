#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

extern int test(unsigned int);

/* This pgm demonstrates 
 * bool datatype of C99 standard.
 * and declaring variable at any place, even in loops.
 */
int main(int argc, char *argv[])
{
	bool a = false;

	for(int i=0; i<10; i++)
	{
		a ^= 1;
		printf("%d ", a);
	}

	printf("\n");

	if(argc > 1) 
	{
		test(atoi(argv[1]));

		argc = atoi(argv[1]);

		if(!(	argc == 1 ||
			argc == 2 ||
			argc == 3 ||
			argc == 4))
		{
			printf("IF OR CONDITION\n");
		}
	}
}
