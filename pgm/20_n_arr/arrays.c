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
   
}
