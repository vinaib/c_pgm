/*
 * Demonstration of size command:
 * on 64 bit systems: one long variable definition reflects changes in output of
 * size. Whereas it consumes 2 int variable defintions to reflect changes in
 * output of size.
 * on 32 bit systems: one int variable definition reflects changes in output of
 * size.
 * Globals/static initialized to zero or unintialized are stored in
 * uninitialized/bss segment. 
 * Globals/static initialzied to non zero are stored in initialzied data segment
 * size of obj files (mm.o) have only code segment, whereas a.out has all
 * segments
 */
#include<stdio.h>
#include<string.h>

long global 	= 1;		
long global_1 	= 0;

void foo(char *bar)
{
	char c[12];

	strcpy(c, bar);
}

int main(int argc, char **argv)
{
	static long st_long = 3;

	if(argc < 2) {
		printf("Enter 12bytes stirng as input ... %s (count = %d)\n", 
				argv[0], argc);
		goto exit_main;
	}

	foo(argv[1]);

exit_main:
	printf("exiting\n");

	return 0;
}
