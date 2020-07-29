#include<stdio.h>
#include<queue.h>
#include<stack.h>

void create_tree(NODE_t *xtree)
{
	/* tree is root node */
	QUEUE_t xq;
	int32_t ivar;
	uint32_t uiret;

	NODE_t *xp, *xn;
	xtree->data = MAGIC_ROOT_DATA;
	
	ivar = init_c_queue(&xq, Q_SIZE);
	if(ivar < 0)
		printf("Error in init_c_queue\n");

	uiret = enqueue(&xq, xtree);

	while(!isEmpty(&xq)) {
		/* fetch node from queue */
		xp = dequeue(&xq);
	
		printf("Enter left child of node %x: ", xp->data);
		scanf("%d", &ivar);

		if(ivar != -1) {
			xn = (NODE_t *)calloc(1, sizeof(NODE_t));
			xn->data = ivar;
			xp->lchild = xn;
			uiret = enqueue(&xq, xn);
		}

		printf("Enter right child of node %x: ", xp->data);
		scanf("%d", &ivar);

		if(ivar != -1) {
			xn = (NODE_t *)calloc(1, sizeof(NODE_t));
			xn->data = ivar;
			xp->rchild = xn;
			uiret = enqueue(&xq, xn);
		}
	}

	delete_c_queue(&xq);

	return;
}

/* Number of traversals (2*number of nodes) + 1*/
void pre_order(NODE_t *xtree)
{
	if(xtree != NULL) {
		printf("%x ", xtree->data);
		pre_order(xtree->lchild);
		pre_order(xtree->rchild);
	}

	return;
}

void in_order(NODE_t *xtree)
{
	if(xtree != NULL) {
		in_order(xtree->lchild);
		printf("%x ", xtree->data);
		in_order(xtree->rchild);
	}
	return;
}

void post_order(NODE_t *xtree)
{
	if(xtree != NULL) {
		post_order(xtree->lchild);
		post_order(xtree->rchild);
		printf("%x ", xtree->data);
	}
	return;
}

void pre_order_iterative(NODE_t *xtree)
{
	STACK_t st;

	init_stack(&st);

	while(xtree != NULL || !isStkEmpty(&st)) {
		if(xtree != NULL) {
			printf("%x ", xtree->data);
			push(&st, xtree);
			xtree = xtree->lchild;
		} else {
			xtree = (NODE_t*)pop(&st);
			xtree = xtree->rchild;
		}
	}

	free_stack(&st);
}

void in_order_iterative(NODE_t *xtree)
{
	STACK_t st;

	init_stack(&st);

	while(xtree != NULL || !isStkEmpty(&st)) {
		if(xtree != NULL) {
			push(&st, xtree);
			xtree = xtree->lchild;
		} else {
			xtree = (NODE_t*)pop(&st);
			printf("%x ", xtree->data);
			xtree = xtree->rchild;
		}
	}

	free_stack(&st);
}

void post_order_iterative(NODE_t *xtree)
{
	STACK_t st;

	init_stack(&st);

	while(xtree != NULL || !isStkEmpty(&st)) {
		if(xtree != NULL) {
			printf("%x ", xtree->data);
			push(&st, xtree);
			xtree = xtree->lchild;
		} else {
			xtree = (NODE_t*)pop(&st);
			xtree = xtree->rchild;
		}
	}

	free_stack(&st);
}

void level_order_traversal(NODE_t *xtree)
{
	QUEUE_t xq;
	NODE_t *p;
	int32_t ivar;
	uint32_t uiret;

	ivar = init_c_queue(&xq, Q_SIZE);
	if(ivar < 0)
		printf("Err in q creation\n");

	if(xtree == NULL)
		goto exit;

	printf("%x ", xtree->data);
	uiret = enqueue(&xq, xtree);

	while(!isEmpty(&xq)) {
		p = dequeue(&xq);

		if(p->lchild) {
			printf("%x ", p->lchild->data);
			enqueue(&xq, p->lchild);
		}
		if(p->rchild) {
			printf("%x ", p->rchild->data);
			enqueue(&xq, p->rchild);
		}
	}

exit:
	return;
}
