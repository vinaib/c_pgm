#include<stdio.h>
#include<queue.h>

#undef TEST_QUEUE

static void test_queue(void)
{
	QUEUE_t q;
	NODE_t na, nb, nc, nd;

	int32_t iret;
	uint32_t uiret;
	NODE_t *xret;

	uint64_t a = 1, b = 2, c = 3, d = 4;

	iret = init_c_queue(&q, 10);

	if(isEmpty(&q)) 
		printf("Queue Empty\n");
	else
		printf("Queue Not Empty\n");
	
	printf("nodes to be inserted %p %p %p %p\n", 
			&na, &nb, &nc, &nd);

	uiret = enqueue(&q, &na);
	uiret = enqueue(&q, &nb);
	uiret = enqueue(&q, &nc);
	uiret = enqueue(&q, &nd);

	xret = dequeue(&q);
	printf("dequeued item %p\n", xret);

	display(&q);

	if(isEmpty(&q)) 
		printf("Queue Empty\n");
	else
		printf("Queue Not Empty\n");

	delete_c_queue(&q);

	if(isEmpty(&q)) 
		printf("Queue Empty\n");
	else
		printf("Queue Not Empty\n");
}

int main(void)
{
#ifndef TEST_QUEUE
	NODE_t root = {NULL, 0, NULL};

	create_tree(&root);
	
	printf("pre order traversal: ");
	pre_order(&root);
	printf("\n");
	printf("in order traversal: ");
	in_order(&root);
	printf("\n");
	printf("post order traversal: ");
	post_order(&root);
	printf("\n");
	printf("pre order iterative traversal: ");
	pre_order_iterative(&root);
	printf("\n");
	printf("in order iterative traversal: ");
	in_order_iterative(&root);
	printf("\n");
	printf("level order traversal: ");
	level_order_traversal(&root);
	printf("\n");
#else
	test_queue();
#endif
}
