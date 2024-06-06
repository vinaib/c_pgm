#ifndef __STACK_HPP__
#define __STACK_HPP__

#include<stdint.h>

struct node 
{
	public:
		int  m_data = -1;
		node *m_next = nullptr;
};

class stack
{
	public:
		~stack();

		int push(int elemement);
		int pop();
		int peek();
		bool isEmpty();
		int lookup(int position);
	private:
		node *head = nullptr;
};

#endif // __STACK_HPP__