#include<stdio.h>

#define PRSIZE(str, x) printf("sizeof(*%s) \t\t%ld sizeof(%s*)\t%ld  ADDR %p\n", str, sizeof(*x), str, sizeof(x), x)
#define PSIZE(str, x) printf("sizeof(%s) \t\t%ld sizeof(&%s)\t%ld  ADDR %p val %d\n", str, sizeof(x), str, sizeof(&x), &x, x)
#define PLSIZE(str, x) printf("sizeof(%s) \t\t%ld sizeof(&%s)\t%ld  ADDR %p val %ld\n", str, sizeof(x), str, sizeof(&x), &x, x)
#define PLLSIZE(str, x) printf("sizeof(%s) \t\t%ld sizeof(&%s)\t%ld  ADDR %p val %lld\n", str, sizeof(x), str, sizeof(&x), &x, x)

void main(void)
{
	short *ps; 	//*ps = 2 ps = 8
	char *pc;  	//*pc = 1 pc = 8
	int  *pi;	//*pi = 4 pi = 8
	long *pl;	//*pl = 4 pl = 8
	long long *pll;	//*pll = 8 pll = 8

	short s;
	char c;
	int i;
	long l;
	long long ll;
	
	PRSIZE("char", pc);
	PSIZE("char", c);

	PRSIZE("int", pi);
	PSIZE("int", i);

	PLSIZE("long", l);
	PRSIZE("long", pl);

	PRSIZE("short", ps);
	PSIZE("short", s);

	PRSIZE("long long", pll);
	PLLSIZE("long long", ll);
}
