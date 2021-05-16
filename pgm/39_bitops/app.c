#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
 * CHAR_MIN -128
 * CHAR_MAX 127
 * UCHAR_MAX 255
 * SHRT_MAX 32767
 * USHRT_MAX 65535
 * INT_MIN, LONG_MIN -2147483648
 * INT_MAX, LONG_MAX  2147483647
 * UINT_MAX, ULONG_MAX 4294967295
*/


#define MIN (0xC6E9)
#define MIN_2 (0xFFFFC6E9)
#define MAX (0x602)
#define NO_OF_ELE ((0xFFFF - MIN + 1) + MAX)
#define NEGATIVE_ELE (0xFFFF - MIN + 1)
#define VOL_MAX 6
#define VOL_MIN -57
#define VOL_STEPS 64
#define VOL_CONV 58  // number of elements on negative scale + 1

int arr[] =
{
52713, 53737, 54761, 55529, 56041, 56553, 57065, 57577,
57833, 58345, 58601, 58857, 59113, 59369, 59625, 59881,
60137, 60393, 60649, 60905, 61161, 61417, 61673, 61929,
62185, 62441, 62697, 62953, 63209, 63465, 63721, 63977,
64233, 64489, 64745, 65001, 65257, 65513, 233, 489,
745, 1001, 1257, 1513 
};

int vol_main(int num);

int main(int argc, char *argv[])
{
 int num;
 int ele = sizeof(arr)/sizeof(arr[0]);
 int i;

 if(argc>1)
 {
   num = atoi(argv[1]);
 }

 printf("%d\n", vol_main(num));

 for(i=0;i<ele;i++)
 {
  printf("%d\n", vol_main(arr[i]));
 }
 
}

int vol_main(int num)
{
 int min = MIN;
 int max = MAX;	
 int total_ele = NO_OF_ELE;
 int imin = MIN_2;
 int conv;
 float fconv = 0;
 const float log_val = 0.00390625;
  
 if(num >=0 && num <= MAX)
 {
  ; 
 }
 else if(num <= 0xFFFF && num >= MIN)
 {
  //2's complement to negative number
  num = -(short)~(num - 1);
 }
 else
 {
  goto EXIT;
 }

 fconv = (float)num * log_val;

 if(fconv<0) 
 {
  fconv = (int)floor(fconv);
 }
 else
 {
  fconv = (int)ceil(fconv);
 }
  
 fconv = ((fconv + VOL_CONV)/VOL_STEPS) * 100;
 
EXIT:
 return (int)fconv;
}
