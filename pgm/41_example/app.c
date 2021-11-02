#include<stdio.h>
#include<stdint.h>

//44 * 4 = 176 + 4 = 180
//44 * 8 = 352 + 8 = 360
//48 * 4 = 192 + 4 = 196
//48 * 8 = 384 + 8 = 392
//88 * 4 = 352 + 4 = 356
//88 * 8 = 704 + 8 = 712
//96 * 4 = 384 + 4 = 388
//96 * 8 = 768 + 8 = 776
#define PRINT_ALL
#define RB_SZ 		8800//7760 //8800
#define ELEMENT_SZ	384

uint32_t element_arr[] =
{176,180,352,360,192,196,384,392,352,356,704,712,384,388,768,776};
uint32_t sample_arr[] = 
{4,4,8,8,4,4,8,8,4,4,8,8,4,4,8,8};

uint8_t sample[776] = {0};

int main(int argc, char *argv[])
{
 uint32_t wr = 0;
 uint32_t iter = 0;
 uint32_t elements = sizeof(element_arr)/sizeof(uint32_t);

#ifdef PRINT_ALL
 uint32_t flag = 1;
#endif

 for(iter = 0; iter < elements; iter++)
 {
  printf("********************** %d ************************\n",
   element_arr[iter]);
  do 
  {
   if(RB_SZ <= (wr + element_arr[iter]))
   {
    uint32_t rem = RB_SZ - wr;
#ifdef PRINT_ALL
    flag = 1;
    printf("\n");
#endif
    if(rem%sample_arr[iter]) 
    {
      printf("%d %d %d\n", element_arr[iter], sample_arr[iter], rem);
    }
   }

   wr = (wr + element_arr[iter]) % RB_SZ;
#ifdef PRINT_ALL
   printf("%4d ", wr);

   if(16 < ++flag)
   {
    flag = 1;
    printf("\n");
   }
#endif
  }while(wr < RB_SZ && wr);

 }//for loop

#if 0
 for(iter = 0; iter<776; iter++)
 {
  printf("%d ", sample[iter]);
  if((iter%16) == 0)
  {
   printf("\n");
  }
 }

 for(iter = 0; iter<776; iter++)
 {
  sample[iter] = iter;
 }

 for(iter = 0; iter<776; iter++)
 {
  printf("%d ", sample[iter]);
  if((iter%16) == 0)
  {
   printf("\n");
  }
 }
#endif
}
