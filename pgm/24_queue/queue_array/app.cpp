#include "queue.hpp"
#include <iostream>

void test_queue(int size)
{
   queue q{size};

   for (int i=0; i<size+1; i++)
   {
      q.enqueue(i);
   }

   for (int i=0; i<size+1; i++)
   {
      std::cout << "dequeue: " << q.dequeue() << '\n';
   }
}


int main(int argc, char *argv[])
{
   test_queue(5);
}
