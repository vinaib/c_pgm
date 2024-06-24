#include "maxHeap.hpp"
#include <vector>
#include <iostream>

maxHeap::maxHeap()
{
   m_arr.push_back(0); 
}

maxHeap::~maxHeap()
{
   
}

void maxHeap::insert(int element)
{
   m_arr.push_back(element);   

   heapify();
}

/**
 * @brief index 1, always contain max element
 * 
 * @return int 
 */
int maxHeap::extract()
{
   int max = m_arr[1];

   int insert = m_arr.back();

   // remove the last element
   m_arr.pop_back();

   int i = 1;
   m_arr[i] = insert;
   int size = m_arr.size() - 1;

   while( i < size)
   {
      if(i*2 > size)      
         break;

      if(m_arr[i*2] > m_arr[(i*2)+1])
      {
         // go left subtree
         if(m_arr[i*2] > m_arr[i])
         {
            std::swap(m_arr[i], m_arr[i*2]);
            i = i * 2;
         }
         else
         {
            break;
         }
      }
      else
      {
         // go right subtree
         if(m_arr[(i*2+1)] > m_arr[i])
         {
            std::swap(m_arr[i], m_arr[(i*2+1)]);
            i = (i * 2) + 1;
         }
         else
         {
            break;
         }
      }    
      
   }

   return max;
}

int maxHeap::extract2()
{
   int max = m_arr[1];

   print();

   m_arr[1] = m_arr.back();
   m_arr.pop_back();

   int i = 1;
   // point to left child
   int j = i * 2;

   std::cout << " size: " << m_arr.size() << " ";

   if(m_arr.size() == 0 || m_arr.size() == UINT64_MAX) 
      return -1;

   print();

   while(j < (m_arr.size()))
   {
      if((j+1) > m_arr.size())
      {
         std::cout << " ELoop: i: " << i << " j: " << j << " ";
         break;
      }
      else
      {
         std::cout << " Loop: i: " << i << " j: " << j << " ";
      }

      if(m_arr[j+1] > m_arr[j])
      {
         // point to right child
         j = j + 1;
      }

      if(m_arr[j] > m_arr[i])
      {
         std:swap(m_arr[j], m_arr[i]);
         i = j;
         j = i * 2;
      }
      else
      {
         break;
      }
   }
   std::cout << " Heapify: ";
   print();
   std::cout << " max: " ;

   return max;
}

/**
 * @brief for 1 element log n
 * for n elements it will be n log n
 * 
 */
void maxHeap::heapify()
{
   int i = (m_arr.size() - 1);

   int element = m_arr[i];

   while( i > 1  && element > m_arr[i/2])
   {
      m_arr[i] = m_arr[i/2];
      i = i/2;
   }

   m_arr[i] = element;
}

void maxHeap::sort()
{
   
}

void maxHeap::print() const
{
   //std::cout << "size: (" << m_arr.size() << "): ";
   // std::cout << "capacity: " << m_arr.capacity() << '\n';

   for(int ele: m_arr)
   {
      std::cout << ele << " ";
   }
   //std::cout << "\n";
}
