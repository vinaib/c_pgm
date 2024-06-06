#ifndef __STACK_HPP__
#define __STACK_HPP__

#include<stdint.h>


class stack 
{
	public:
	stack(int size);

	~stack();

	bool isEmpty();
	bool isFull();
	int push(int element);
	int pop();
	int peek();

	private:
		int m_size;
		int m_top = -1;
		int *s;
};

#endif // __STACK_HPP__