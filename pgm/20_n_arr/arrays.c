#include<stdio.h>
#include<stdlib.h>

int main()
{
   int rowIndex, columnIndex;

   int a[3][4] = 
      { {1,2,3,4},
        {5,6,7,8},
        {9,0,1,2} };

   // array of 3 pointers to hold the address of
   // array of size 4
   int *p[3];

   p[0] = (int*)malloc(sizeof(int) * 4);
   p[1] = (int*)malloc(sizeof(int) * 4);
   p[2] = (int*)malloc(sizeof(int) * 4);

   // array of double pointers
   int **pd;

   // pd is double pointer, so return double pointer
   // and also size if pointer. 
   // pd[0] is being array element, it is single
   // dimensional. so no need of typecasting to 
   // double pointer and size will be size of int
   // as it holds the integer numbers not address.
   pd    = (int**)malloc(sizeof(int*) * 3);
   pd[0] = (int*)malloc(sizeof(int) * 4);
   pd[1] = (int*)malloc(sizeof(int) * 4);
   pd[2] = (int*)malloc(sizeof(int) * 4);

   for(rowIndex = 0; rowIndex < 3; rowIndex++)
   {
      for(columnIndex = 0; columnIndex < 4; columnIndex++)
      {
         printf("%d ", a[rowIndex][columnIndex]);
         p[rowIndex][columnIndex] = a[rowIndex][columnIndex];
         pd[rowIndex][columnIndex] = a[rowIndex][columnIndex];
         printf("%d ", p[rowIndex][columnIndex]);
         printf("%d ", pd[rowIndex][columnIndex]);
      }
      printf("\n");
   }

   // free pointers
   free(p[0]); 
   free(p[1]); 
   free(p[2]); 

   // free double pointers
   free(pd[0]);
   free(pd[1]);
   free(pd[2]);
   free(pd);

   printf("size of int                             %ld\n", sizeof(int));
   // first row base address / first location a[0][0]
   printf("first row base addr a                         %p \n", a);
   printf("first row base addr *(a)/*a                   %p \n", *(a));
   printf("data at first row base addr *(*(a))           %d \n", *(*(a)));
   // first row base address / second location a[0][1]
   printf("first row base addr second *(a)+1             %p \n", *(a)+1);
   printf("data at first row base addr second *(*(a)+1)  %d \n", *(*(a)+1));
   // first row base address / third location a[0][2]
   printf("first row base addr third *(a)+2              %p \n", *(a)+2);
   printf("data at first row base addr third *(*(a)+2)   %d \n", *(*(a)+2));
   // first row base address / fourth location a[0][3]
   printf("first row base addr fourth *(a)+3             %p \n", *(a)+3);
   printf("data at first row base addr fourth *(*(a)+3)  %d \n", *(*(a)+3));
   // second row base address /first location
   printf("second row base addr a+1                      %p \n", a+1);
   printf("second row base addr *(a+1)                   %p \n", *(a+1));
   printf("data at second row base addr *(*(a+1))        %d \n", *(*(a+1)));
   // second row base address /second location
   // printf("second row base addr (a+1)+1               %p \n", (a+1)+1);
   // (a+1)+1 is equal to (a+2) this points to third row, not the second
   // element in second row. To access the second element in second row
   // correct statement is *(a+1)+1
   printf("second row base addr *(a+1)                   %p \n", *(a+1)+1);
   printf("data at second row base addr second *(*(a+1)) %d \n", *(*(a+1)+1));
   // third row base address
   printf("third row base addr a+2                       %p \n", a+2);
   printf("third row base addr *(a+2)                    %p \n", *(a+2));
   printf("data at third row base addr *(*(a+2))         %d \n", *(*(a+2)));
   
}
