#include "common.hpp"
#include <iostream>

void printArr(vector<int>& arr)
{
   for(auto a: arr)
   {
      std::cout << a << " ";
   }

   std::cout << '\n';
}
