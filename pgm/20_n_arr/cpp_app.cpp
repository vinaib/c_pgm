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

int insertElement(arr_t *pArr, int ele, int idx)
{
   int i;

   if(pArr->length > pArr->size)
   {
      // Array full
      return -1;
   }

   if(idx > pArr->length)
   {
      // invalid index
      return -2;
   }

   if(idx == pArr->length)
   {
      return appendElement(pArr, ele);
   }

   // shift elements of array, start from last index
   for(i=pArr->length ; i > idx; i--)
   {
      pArr->A[i] = pArr->A[i-1];
   }

   pArr->A[i] = ele;

   pArr->length++;

   return 0;
}

int deleteElement(arr_t *pArr, int idx)
{
   int ele = pArr->A[idx];

   int i;

   if(idx > pArr->length)
   {
      //idx exceeded length
      return -1;
   }

   if(idx < 0)
   {
      // index cannot be negative
      return -2;
   }

   // shift elements of array, start from given index
   for(i=idx; i < (pArr->length-1); i++)
   {
      pArr->A[i] = pArr->A[i+1];
   }

   pArr->length--;

   return ele;
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

   insertElement(&arr, 10, 10);
   insertElement(&arr, 10, 3);

   displayArray(&arr); 

   deleteElement(&arr, 3);

   displayArray(&arr); 
   
   deleteArray(&arr);
   
   displayArray(&arr); 
   return 0;
}

