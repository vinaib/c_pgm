#include <iostream>

int main(int argc, char* argv[])
{
   char str[12];

   std::cin.getline(str, 10);

   std::cout << "helloworld: " << str << '\n';

   return 0;
}