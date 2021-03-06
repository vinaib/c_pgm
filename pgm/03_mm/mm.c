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
#include<unistd.h>

long global 	= 1;		
long global_1 	= 0;

int main(void)
{
	static long st_long = 3;
	int local;

	printf("hello world\n");

	global = local;

	global++;

	while(1) {
		sleep(10);
	}

	return 0;
}
