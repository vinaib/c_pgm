#include<stdio.h>
#include<stdint.h>


int main(void)
{
	uint32_t i = 0x11223344;

	uint8_t *pc;

	uint8_t **ppc;

	pc = (uint8_t*)&i;

	uint8_t c;

	ppc = &pc;

	c = *((uint8_t *)&i);

	printf("address of i %p\n", &i);
	printf("value of i %x\n", i);
	printf("value of pc %p\n", pc);
	printf("address of pc %p\n", &pc);
	printf("value pointing by pc %x\n", *pc);
	printf("value pointing by pc %x\n", *(pc+1));
	printf("value pointing by pc %x\n", *(pc+2));
	printf("value pointing by pc %x\n", *(pc+3));
	printf("value of ppc %p\n", ppc);
	printf("address of ppc %p\n", &ppc);
	printf("value pointing by ppc %x\n", *(*(ppc)));
	printf("value pointing by ppc %x\n", *(*(ppc)+1));
	printf("value pointing by ppc %x\n", *(*(ppc)+2));
	printf("value pointing by ppc %x\n", *(*(ppc)+3));
	printf("value of c %x\n", c);
}
