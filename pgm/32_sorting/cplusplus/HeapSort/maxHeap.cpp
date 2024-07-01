#include "maxHeap.hpp"
#include <vector>
#include <iostream>

maxHeap::maxHeap() : m_size(0)
{
   m_size++;
   m_arr.push_back(0); 
}

maxHeap::~maxHeap()
{
   
}

void maxHeap::insert(int element)
{
   m_size++;
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
   // get the max element
   int max = m_arr[1];

   // get the last element
   //int insert = m_arr.back();

   // swap first and last element
   std::swap(m_arr[1], m_arr[m_size-1]);

   // remove the last element
   //m_arr.pop_back();
   m_size--;

   int i = 1;
   //m_arr[i] = insert;
   //int size = m_arr.size() - 1;
   int size = m_size;

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

/**
 * @brief after extract max element push it to last
 * 
 * @return int 
 */
int maxHeap::extract2()
{
   int max = m_arr[1];
   std::cout << "<<< ";

   print();

   // m_arr[1] = m_arr.back();
   // m_arr.pop_back();
   std::swap(m_arr[1], m_arr[m_size - 1]);
   m_size--;

   int i = 1;
   // point to left child
   int j = i * 2;

   //std::cout << " size: " << m_arr.size() << " ";
   //std::cout << " size: " << m_size << " ";

   // if(m_arr.size() == 0 || m_arr.size() == UINT64_MAX) 
   if(m_size == 0 || m_size == UINT64_MAX) 
      return -1;

   if(m_size == 3)
   {
      if(m_arr[j] > m_arr[i])
      {
         std::swap(m_arr[j], m_arr[i]);
      }
   }

   print();

   // while(j < (m_arr.size()))
   while(j < (m_size-1) && m_size > 3)
   {
      // if((j+1) > m_arr.size())
      if((j+1) > m_size-1)
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
   std::cout << " max: >>> " ;

   return max;
}

/**
 * @brief for 1 element log n
 * for n elements it will be n log n
 * 
 */
void maxHeap::heapify()
{
   // int i = (m_arr.size() - 1);
   int i = (m_size - 1);

   int element = m_arr[i];

   while( i > 1  && element > m_arr[i/2])
   {
      m_arr[i] = m_arr[i/2];
      i = i/2;
   }

   m_arr[i] = element;
}

/**
 * @brief heapify the given array.
 * Start traversing array from right to left
 * Leaf nodes are heap by itself
 * This way of heapify is faster than first way.
 * Half of the elements are leaf nodes, and they are heap by itself. 
 * We have to process only other half. 
 * 
 * @param arr 
 * Given array starts from index 0 to n-1
 * 
 * for heap, we have to store it from 1 to n-1, 0 is ignored.
 */
void maxHeap::heapify2(vector<int>& arr)
{
   int n = arr.size();

   // update size
   m_size += n;

   // 0 to size()
   for(int copyIdx = 0; copyIdx < n; copyIdx++)
   {
      m_arr.push_back(arr[copyIdx]);
   }

   // 1 to size()
   n = m_arr.size()-1;
   
   // start from size - 1 to 1. Do not process 0
   for(int i = n; i > 0; i--)
   {
      // if leaf node, just increment
      if(i*2 > n)
      {
         // do nothing, no child
         std::cout << " L ";
      }
      // if intermediate node, compare with its children
      else
      {
         int k = i;
         int j = 2 * k;

         // go down till leaf node
         while(j < n)
         {
            std::cout << " I ";
            if(m_arr[j+1] > m_arr[j])
            {
                  j++;
            }
            
            if(m_arr[j] > m_arr[k])
            {
               std::swap(m_arr[k], m_arr[j]);
               k = j;
               j = 2 * k;
            }
            else
            {
               break;
            }
         }
      }
   }

   std::cout << " \n ";
}

void maxHeap::sort()
{
   
}

void maxHeap::print() const
{
   //std::cout << "size: (" << m_arr.size() << "): ";
   // std::cout << "capacity: " << m_arr.capacity() << '\n';
   std::cout << " size: (" << m_size << "): ";
   for(int ele: m_arr)
   {
      std::cout << ele << " ";
   }
   //std::cout << "\n";
}
