#include <iostream>
#include <cmath>
#include <cstdlib>

bool isPrime(int number)
{
   if(number == 1 || number == 2)
   {
      return true;
   }

   for(int i = 2; i < number; i++)
   {
      if( (number % i) == 0)
      {
         return false;
      }
   }

   return true;
}



int main(int argc, char *argv[])
{
   if (argc < 2 || argc > 2)
   {
      return -1;
   }

   int number = atoi(argv[1]);

   std::cout << std::boolalpha << "is number " << number << " prime ? " << isPrime(number) << '\n';

}