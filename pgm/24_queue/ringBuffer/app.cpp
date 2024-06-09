#include "rb.hpp"
#include <iostream>

int main(int argc, char *argv[])
{

   rb r{5};

   std::cout << std::boolalpha << r.isFull() << '\n';
   std::cout << r.isEmpty() << '\n';

   for (int i = 0; i<7; i++)
   {
      if(r.enqueue(i) != -1)
      {
         std::cout << "added to rb\n";
      }
      else
      {
         std::cout << "rb full\n";
      }
   }

   for(int i = 0; i<7; i++)
   {
      int val;
      if((val = r.dequeue()) != -1)
      {
         std::cout << "read Val: " << val << '\n';
      }
      else
      {
         std::cout << "rb empty\n";
      }
   }

      for (int i = 0; i<7; i++)
   {
      if(r.enqueue(i) != -1)
      {
         std::cout << "added to rb\n";
      }
      else
      {
         std::cout << "rb full\n";
      }
   }
}