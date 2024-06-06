#include"stack.hpp"
#include<iostream>
#include<stdlib.h>

stack::stack(int size)
: m_size(size), s{new int[size]} 
{

}

stack::~stack()
{
	delete[] s;
	s = nullptr;
}

bool stack::isEmpty()
{
	if(m_top == -1)
	{
		return true;
	}

	return false;
}

bool stack::isFull()
{
	if(m_top == (m_size - 1))
	{
		return true;
	}

	return false;
}

int stack::push(int element)
{
	int ret = -1;

	if(!isFull())
	{
		s[++m_top] = element;
		ret = m_top;
	}
	else
	{
		std::cout << "stack overflow\n";
	}

	return ret;
}

int stack::pop()
{
	int x = -1;

	if(!isEmpty())
	{
		x = s[m_top--];
	}
	else
	{
		std::cout << "stack underflow\n";
	}

	return x;
}

int stack::peek()
{
	int x = -1;

	if(!isEmpty())
	{
		x = s[m_top];
	}

	return x;
}

