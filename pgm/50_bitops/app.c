#include<stdio.h>

/* reference linux sources: 
 * arch/arm/include/asm/bitops.h
 */
void set_bit(unsigned int bit, volatile unsigned long *p)
{
   // bit not exceed 31, in 32 bit machine
	unsigned long mask = 1UL << (bit & 31);

	//p += bit >> 5;

	*p |= mask;
}

void clear_bit(unsigned int bit, volatile unsigned long *p)
{
   // bit value should not exceed 31, 
   unsigned long mask = 1ul << (bit & 31);

   // (bit >> 5) should yield 0, so p += 0, p still point to p
   // p is not altered
   //p += (bit >> 5);

   *p &= ~mask;
}

void change_bit(unsigned int bit, volatile unsigned long *p)
{
   unsigned long mask = 1ul << (bit & 31);

   //p += (bit >> 5);

   *p ^= mask;
}


int main()
{
   unsigned long a = 4;

   printf("size of int %ld size of long %ld\n", sizeof(int), sizeof(long));

   set_bit(30, &a);

   printf("After set bit %lu %lx\n", a, a);

   clear_bit(30, &a);

   printf("After clear bit %lu %lx\n", a, a);

   change_bit(30, &a);

   printf("After change bit %lu %lx\n", a, a);

   return 0;
}
