#include "stack.h"
#include<stdio.h>

void test_stack(void)
{
	STACK_t st;

	int32_t iret;
	uint64_t i;
	int64_t i64data;
	
	iret = init_stack(&st);
	if(iret < 0) {
		printf("stk init failed\n");
		goto exit_1;
	}

	for(i=0; i<10; i++) {
		push(&st, (void *)i);
	}

	printf("stack elements: ");
	display_stack(&st);
	printf("\n");
	printf("getTop %p\n", get_top(&st));

	printf("peek 5 %ld\n", (uint64_t)peek(&st, 5));
	printf("peek 1 %ld\n", (uint64_t)peek(&st, 1));
	printf("peek 9 %ld\n", (uint64_t)peek(&st, 9));


	i64data = (int64_t)pop(&st);
	printf("pop %ld\n", i64data);
	i64data = (int64_t)pop(&st);
	printf("pop %ld\n", i64data);
	i64data = (int64_t)pop(&st);
	printf("pop %ld\n", i64data);
	printf("getTop %p\n", get_top(&st));

	printf("stack elements: ");
	display_stack(&st);
	printf("\n");

	free_stack(&st);
	printf("getTop %p\n", get_top(&st));

	printf("stack elements: ");
	display_stack(&st);
	printf("\n");

	printf("isEmpty %d\n", isEmpty(&st));
	printf("isFull %d\n", isFull(&st));
	printf("getTop %p\n", get_top(&st));
exit_1:
	return;
}

int main(void)
{
	test_stack();
}

