#include "stack.hpp"
#include <iostream>

void test_stack(int size)
{
	stack st{size};

	for(int i=0; i<=size; i++) 
	{
		st.push(i);
	}

	printf("getTop %d\n", st.peek());


	for(int i=0; i<=size; i++) 
	{
		std::cout << st.pop() << "\n";
	}
}

int main(int argc, char *argv[])
{
	test_stack(5);
}

