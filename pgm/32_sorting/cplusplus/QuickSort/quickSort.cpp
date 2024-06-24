#include <iostream>
#include <algorithm>
#include "quickSort.hpp"
#include "common.hpp"

vector<int> quick_sort(vector<int> &arr)
{
   std::cout << "Array Size: " << arr.size() << '\n';

   // Write your code here.
   partition(arr, 0, arr.size() - 1);

   return {arr};
}

void partition(vector<int>&arr, int start, int end)
{
   std::cout << "Partition: " << start << " : " << end << '\n';

   // leaf node worker
   if(start >= end)
   {
      std::cout << " :ln: \n";
      return;
   }   

   // internal node worker
   int smallerIdx = start + 1;
   int biggerIdx = end;

   while(smallerIdx <= biggerIdx)
   {
      if(arr[smallerIdx] < arr[start])
      {
         smallerIdx++;
      }
      else if(arr[biggerIdx] > arr[start])
      {
         biggerIdx--;
      }
      else
      {
         std::swap(arr[smallerIdx], arr[biggerIdx]);
         std::cout<< "after Swap SmallerIdx and biggerIdx\n";
         printArr(arr);
         smallerIdx++;
         biggerIdx--;
      }

   }
   std::cout << "Swap: " << arr[start] << " " << arr[biggerIdx] << " smallerIdx: " << smallerIdx << " biggerIdx: " << biggerIdx << '\n';

   std::swap(arr[start], arr[biggerIdx]);
   std::cout << "after pivot and biggerIdx swap\n";
   printArr(arr);

   partition(arr, start, biggerIdx-1);
   partition(arr, smallerIdx, end);
}
