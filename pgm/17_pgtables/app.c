#include<stdio.h>

#define MEM_SIZE 	0xFFFFFFFF
#define L1_SEC_SIZE 0x000FFFFF
#define L2_PG_TABLE 0x0

//TODO

int main(void)
{
	int i=0;
	unsigned int mem_sz = (unsigned int)MEM_SIZE;
	unsigned int l1_sz = (unsigned int)L1_SEC_SIZE;
	unsigned int l1_entries = mem_sz / l1_sz;

	printf("%d L1 entries\n", l1_entries);
}
