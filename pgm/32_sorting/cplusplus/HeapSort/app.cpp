#include "common.hpp"
#include "maxHeap.hpp"
#include <array>
#include <iostream>


void createHeap(maxHeap &h)
{
   std::array<int,8> arr = {30,40,15,25,12,35,6,5};
   // std::array<int,3> arr = {6,5,12};

   for(int i = 0;i<arr.size();i++)
   {
      h.insert(arr[i]);
   }
}


void createHeap2(maxHeap &h)
{
   std:vector<int> arr = {5, 8, 3, 9, 4, 1, 7};
   h.heapify2(arr);
   h.print();
}

int main(int argc, char *argv[])
{
   maxHeap mh;

   createHeap2(mh);   

   //createHeap(mh);
   //mh.print();
   std::cout << "\n";

#if 0 
   std::cout << "max element: " << mh.extract() << "\n";
   std::cout << "max element: " << mh.extract() << "\n";
   std::cout << "max element: " << mh.extract() << "\n";
   std::cout << "max element: " << mh.extract() << "\n";
   std::cout << "max element: " << mh.extract() << "\n";
   std::cout << "max element: " << mh.extract() << "\n";
   std::cout << "max element: " << mh.extract() << "\n";
   std::cout << "max element: " << mh.extract() << "\n";
#else
   std::cout << "max element: " << mh.extract2() << "\n";
   std::cout << "max element: " << mh.extract2() << "\n";
   std::cout << "max element: " << mh.extract2() << "\n";
   std::cout << "max element: " << mh.extract2() << "\n";
   std::cout << "max element: " << mh.extract2() << "\n";
   std::cout << "max element: " << mh.extract2() << "\n";
   std::cout << "max element: " << mh.extract2() << "\n";
   //std::cout << "max element: " << mh.extract2() << "\n";
#endif

}