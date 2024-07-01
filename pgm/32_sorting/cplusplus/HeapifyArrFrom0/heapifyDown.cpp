#include <iostream>
#include <vector>
#include "common.hpp"


void heapify(std::vector<int>& arr, int parent, int noOfElements)
{
   // left child
   int child = parent * 2 + 1;

   while(child < noOfElements)
   {
      if(((child + 1) < noOfElements) && arr[child + 1] > arr[child])
      {
         child += 1;
      }

      if(arr[child] > arr[parent])
      {
         std::swap(arr[child], arr[parent]);
         parent = child;
         child = 2 * parent + 1;
      }
      else
      {
         break;
      }
   }
}

void buildHeap(std::vector<int> &arr, int noOfElements)
{
   for(int i = (noOfElements/2) -1; i >= 0; i--)
   {
      heapify(arr, i, noOfElements);
   }
}

int extractMax(std::vector<int>& arr, int &noOfElements)
{
   int max = arr[0];
   int lastIndex = noOfElements - 1;

   std::swap(arr[0], arr[lastIndex]);

   // reduced the size for deleted element
   noOfElements -= 1;

   buildHeap(arr, noOfElements);

   return max;
}

void heapSort(std::vector<int> &arr)
{
   int noOfElements = arr.size();
   
   // Decreasing array size
   for(int i = 0; i < arr.size(); i++)
   {
      extractMax(arr, noOfElements);
   }
}

int main(int argc, char *argv[])
{
   std::vector<int> arr {5, 8, 3, 9, 4, 1, 7};
   std::cout << "given array: ";
   printArr(arr);

   buildHeap(arr, arr.size());

   std::cout << "Heap Sort: ";
   heapSort(arr);

   printArr(arr);
}
