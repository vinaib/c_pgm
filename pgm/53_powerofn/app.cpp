#include <iostream>

int powerof2(int k)
{
   std::cout << ">>> " << k << '\n';

   if( 0 == k)
   {
      return 1;
   }
   else
   {
      return 2 * powerof2(k-1);
   }
}

int optPowerof2(int k)
{
   std::cout << ">>> " << k << '\n';

   if( 0 == k)
   {
      return 1;
   }
   else if ( 1 == k)
   {
      return 2;
   }
   else
   {
      int odd = (k % 2);
      int power = (k / 2);

      if(odd)
      {
         return 2 * optPowerof2(power) * optPowerof2(power);
      }
      else
      {
         return optPowerof2(power) * optPowerof2(power);
      }
   }
}

int main(int argc, char *argv[])
{
   int power = 5;

   if (argc >= 2)
   {
      power = atoi(argv[1]);
   }

   std::cout << "Power of 2: " << powerof2(power) << '\n';
   std::cout << "Power of 2: " << optPowerof2(power) << '\n';

   return 0;
}