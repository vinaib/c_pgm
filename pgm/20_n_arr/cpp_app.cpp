#include<iostream>

using namespace std;

typedef struct _arr_t
{
   int *A;
   int size;
   int length;
}arr_t;

int initArray(arr_t *pArr, int sz)
{
   pArr->A = new int[sz];
   pArr->size = sz;
   pArr->length = 0;
   
   return 0;
}

void deleteArray(arr_t *pArr)
{
   delete pArr->A;
   pArr->length = pArr->size = 0;
}

int appendElement(arr_t *pArr, int ele)
{
   if(pArr->length > pArr->size)
   {
      return -1;
   }

   pArr->A[pArr->length] = ele;

   pArr->length++;

   return 0;
}

void displayArray(arr_t *pArr)
{
   if(!pArr->length)
   {
      cout << "Array Empty";
   }

   for(int i=0; i<pArr->length; i++)
   {
      cout << pArr->A[i] << " ";
   }

   cout << "\n";
}

int main(void)
{
   arr_t arr;

   initArray(&arr, 20);

   displayArray(&arr); 
   
   appendElement(&arr, 1);
   appendElement(&arr, 2);
   appendElement(&arr, 3);
   appendElement(&arr, 4);
   appendElement(&arr, 5);
   appendElement(&arr, 6);

   displayArray(&arr); 
   
   deleteArray(&arr);
   
   displayArray(&arr); 
   return 0;
}

