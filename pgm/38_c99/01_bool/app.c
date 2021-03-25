#include<stdio.h>
#include<stdbool.h>

extern int test();

/* This pgm demonstrates 
 * bool datatype of C99 standard.
 * and declaring variable at any place, even in loops.
 */
int main(void)
{
	bool a = false;

	for(int i=0; i<10; i++)
	{
		a ^= 1;
		printf("%d ", a);
	}

	printf("\n");

	test();
}
