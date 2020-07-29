#include<stdio.h>
#include<stdint.h>

int main(void)
{
	register uint32_t current_sp asm("sp");

	uint32_t a;

	uint32_t *p = (uint32_t*)(&a);

	p = (uint32_t*)0xC0000000;

	printf("hello world %#x %p %p\n", current_sp, &a, p);

	for(uint32_t i = 0; i<0x200 ; i++) {
		printf("%#x ", p[i]);
		if(!(i%16)) printf("\n");
	}

	//*p = 10;

}
