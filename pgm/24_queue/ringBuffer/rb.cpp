#include "rb.hpp"
#include <iostream>

rb::rb(int size):
m_arr{new int[size]}, m_size{size}
{
   std::cout << "rb Created of size: " << size <<'\n';
}

rb::~rb()
{
   delete m_arr;
   m_arr = nullptr;

   std::cout << "rb deleted\n";
}

int rb::enqueue(int element)
{
   if(isFull())
   {
      return -1;
   }

   // add element
   m_arr[m_write] = element;

   // update write index
   m_write = (m_write + 1) % m_size;

   // check for full
   m_full = (m_read == m_write);

   return 0;
}

int rb::dequeue()
{
   if(isEmpty())
   {
      return -1;
   }

   // as we are consuming reset the full flag
   m_full = 0;

   // fetch the current item
   int val = m_arr[m_read];

   // update the read pointer
   m_read = (m_read + 1) % m_size;

   return val;
}

bool rb::isFull()
{
   return m_full;
}

bool rb::isEmpty()
{
   return (!m_full && (m_read == m_write));
}
