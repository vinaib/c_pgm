#include<iostream>
#include<vector>
#include "common.hpp"
#include <algorithm>

//5 8 3 9 4 1 7

void countSort(std::vector<int>&arr, std::vector<int>& aux)
{
   for(int i = 0; i<arr.size(); i++)
   {
      if(arr[i])
      {
         aux[arr[i]]++;
         std::cout << arr[i] << " ";
      }
   }

   std::cout << "\n";
   printArr(aux);

   for(int i = 0; i<aux.size(); i++)
   {
      int val = aux[i];

      for(int j = 0; j< val; j++)
      {
         std::cout << i << " ";
      }
   }

   std::cout << "\n";
}

int main(int argc, char *argv[])
{
   std::vector<int> arr {5,1,3,4,4,1,7,9,4,3,2,6,6,7,8};

   auto max = max_element(arr.begin(), arr.end());
   std::cout << "max is: " << *max << '\n';

   std::vector<int> aux (*max+1,0);

   std::cout << "Size of arr: " << arr.size() << '\n';
   std::cout << "Size of aux: " << aux.size() << '\n';

   printArr(arr);
   printArr(aux);

   countSort(arr, aux);
}