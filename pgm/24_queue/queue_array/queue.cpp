#include "queue.hpp"
#include <iostream>

queue::queue(int size):
m_arr{new int[size]}, m_size{size} , m_front{-1}, m_rear{-1}
{

}

queue::~queue()
{
   if(m_arr != nullptr)
      delete []m_arr;

   m_arr = nullptr;
}

int queue::enqueue(int element)
{
   if(!isFull())
   {
      m_arr[++m_rear] = element;
      return 0;
   }
   else
   {
      std::cout << "queue full\n";
   }

   return -1;
}

int queue::dequeue()
{
   if(!isEmpty())
   {
      return m_arr[++m_front];
   }
   else
   {
      std::cout << "queue empty\n";
   }

   return -1;
}

bool queue::isEmpty()
{
   if(m_front == m_rear)
   {
      return true;
   }

   return false;
}

bool queue::isFull()
{
   if(m_rear == (m_size - 1)) 
      return true;

   return false;
}
