#include<stdio.h>
#include<stdint.h>

#define MEM_SIZE 	0xFFFFFFFF
#define L1_SEC_SIZE 0x000FFFFF
#define L2_PG_TABLE 0x0

//TODO

int main(void)
{
	uint32_t i=0;
	uint32_t pages = 0;
	uint32_t page_1m = 0;
	uint32_t page_256 = 0;
	unsigned int mem_sz = (unsigned int)MEM_SIZE;
	unsigned int l1_sz = (unsigned int)L1_SEC_SIZE;
	unsigned int l1_entries = mem_sz / l1_sz;

	/* 1M size: span entire 4GB*/
#ifdef PAGE_1M
	for(i=0;i<4096;i++) {
		printf("0x%08x\n", page_1m);
		page_1m = page_1m + (1<<20);
	}
#endif

	for(i=0;i<256;i++) {
		printf("0x%08x\n", page_256);
		page_256 = page_256 + (1<<12);
	}

	/* 4K size: span entire 4GB */
#ifdef PAGE_4K	
	for(i=0;i<1048576;i++) {
		printf("0x%08x\n", pages);
		pages = pages + (1<<12);
	}
#endif

}
