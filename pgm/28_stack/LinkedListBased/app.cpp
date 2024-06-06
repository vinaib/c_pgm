#include "stack.hpp"
#include<iostream>

void test_stack(int size)
{
	stack st;

	for(int i=0; i<size; i++) 
	{
		st.push(i);
	}

	std::cout << "getTop: " << st.peek() << '\n';

	for(int i=0; i<(size*2); i++)
	{
		std::cout << "lookup: " << st.lookup(i) << '\n'; 
	}

	for(int i=0; i<size; i++) 
	{
		std::cout << "pop: " << st.pop() << '\n';
	}
}

int main(void)
{
	test_stack(5);
}

