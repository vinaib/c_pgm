#include<stdint.h>
#include<stdio.h>

#define GPFSEL0	0x7E200000
#define GPFSEL1 0x7E200004
#define GPFSEL2 0x7E200008
#define GPFSEL3	0x7E20000C
#define GPFSEL4 0x7E200010
#define GPFSEL5 0x7E200014

void GPIO_dir_output(int32_t pin_no)
{
	int32_t sel_reg = (pin_no) / 10;

	switch(sel_reg) {
		case 0: printf("base 0x%x %d %d\n", GPFSEL0, sel_reg, pin_no); break;
		case 1: printf("base 0x%x %d %d\n", GPFSEL1, sel_reg, pin_no); break;
		case 2: printf("base 0x%x %d %d\n", GPFSEL2, sel_reg, pin_no); break;
		case 3: printf("base 0x%x %d %d\n", GPFSEL3, sel_reg, pin_no); break;
		case 4: printf("base 0x%x %d %d\n", GPFSEL4, sel_reg, pin_no); break;
		case 5: printf("base 0x%x %d %d\n", GPFSEL5, sel_reg, pin_no); break;
	}
}

int32_t main(void)
{
	int32_t i;

	for(i=0; i<53; i++)
		GPIO_dir_output(i);
	
}
