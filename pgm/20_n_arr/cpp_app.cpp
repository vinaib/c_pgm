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

/*
 * Time Complexity
 * O(1)
 */
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

/*
 * Time Complexity
 * O(N)
 */
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

/*
 * Time Complexity
 * Best time: O(1), insert element at last
 * Worst time: O(N), insert element at first
 */
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

/*
 * Time Complexity
 * Best time: O(1), delete element at last
 * Worst time: O(N), delete element at first
 */
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

void swap(int *pE1, int *pE2)
{
   *pE1 = *pE1 + *pE2;
   *pE2 = *pE1 - *pE2;
   *pE1 = *pE1 - *pE2;
}

/*
 * Search: Linear serach
 * Requirement: Unique elements. if there are duplicates you may get any one of
 * the index not the other index or all the indexes having the same element. It
 * returns once given element is identified.
 *
 * For linear search, are elements need to be sorted? - No such requirement
 *
 * Terms:
 * -----
 * key: element to search
 * Successful search: if key is found
 * Un-Successful search: if key is not found
 *
 * Time Complexity:
 * for successful search:
 * Best time O(1)
 * Worst time O(N)
 * for unsuccessful search:
 * Best/Worst time O(N)
 *
 * Improvement of linear search
 * By Transposition: Once key element is found, swap key element with its
 * previous element. swap(i, i-1)
 *
 * By Move to Front/Hear: Once key element is found, swap key element with
 * first element swap(i, 0)
 */
int linearSearch(arr_t *pArr, int key)
{
   int loopIndex;

   for(loopIndex = 0; loopIndex < pArr->length; loopIndex++)
   {
      if(key == pArr->A[loopIndex])
      {
         if(loopIndex != 0)
         {
            // linear search improvement by transposition
            swap(&pArr->A[loopIndex], &pArr->A[loopIndex-1]);
            // linear search improvement by move to front/head
            //swap(&pArr->A[loopIndex], &pArr->A[0]);
         }
         return loopIndex;
      }
   }
   return -1;
}

/*
 * Search: Binary Search
 * Minimum Reuqirement: All elements must be sorted
 * Procedure:
 * Always search for the key element in the middle of the sorted list and
 * divide the list in to two.
 *
 * Requires 3 indexes:
 * low, high, Mid values.
 * Initially:
 * low = points to begin
 * high = points to end
 * Mid = floor ( (low + high) / 2 )
 *
 * Time Complexity: O(log2 N)
 */
int IterativeBinarySearch(arr_t *pArr, int key)
{
   int low;
   int high;
   int mid;

   low = 0;
   high = pArr->length;

   while(low <= high)
   {
      mid = (low + high) / 2;

      if(key == pArr->A[mid])
      {
         return mid;
      }
      else if(key < pArr->A[mid])
      {
         high = (mid-1);
      }
      else
      {
         low = (mid+1);
      }
   }

   return -1;
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

   deleteElement(&arr, 5);
   displayArray(&arr);

   cout << linearSearch(&arr, 4) << endl;
   cout << linearSearch(&arr, 100) << endl;
   displayArray(&arr);
   cout << linearSearch(&arr, 4) << endl;
   displayArray(&arr);
   cout << linearSearch(&arr, 4) << endl;
   displayArray(&arr);
   cout << linearSearch(&arr, 4) << endl;
   displayArray(&arr);
   cout << linearSearch(&arr, 4) << endl;
   displayArray(&arr);
   
   deleteArray(&arr);
   displayArray(&arr); 

   // sorted array: Demonstrating Binary search
   initArray(&arr, 15);
   appendElement(&arr, 4);
   appendElement(&arr, 8);
   appendElement(&arr, 10);
   appendElement(&arr, 15);
   appendElement(&arr, 18);
   appendElement(&arr, 21);
   appendElement(&arr, 24);
   appendElement(&arr, 27);
   appendElement(&arr, 29);
   appendElement(&arr, 33);
   appendElement(&arr, 34);
   appendElement(&arr, 37);
   appendElement(&arr, 39);
   appendElement(&arr, 41);
   appendElement(&arr, 43);
   displayArray(&arr);

   cout << "search 34: " << IterativeBinarySearch(&arr, 34) << endl;
   cout << "search 19: " << IterativeBinarySearch(&arr, 19) << endl;
   deleteArray(&arr);

   return 0;
}

