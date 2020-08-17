#include<queue.h>
#include<stdlib.h>
#include<stdio.h>

NODE_t *alloc_node()
{
	return (NODE_t* )calloc(1, sizeof(NODE_t));
}

EERR_t init_queue(QUEUE_t *q)
{
	q->xfront = q->xrear = NULL;
}

EERR_t enqueue(QUEUE_t *q, int32_t i)
{
	NODE_t *pnew = alloc_node();

	if(pnew == NULL) 
		return eQUEUE_FULL;

	pnew->ele = i;

	/* if i is first element */
	if(q->xrear == NULL) {
		q->xfront = q->xrear = pnew;
	} 
	/* insert at rear */
	else {
		q->xrear->next = pnew;
		q->xrear = pnew;
	}

	return eQUEUE_NOERR;
}

EERR_t dequeue(QUEUE_t *q, int32_t *d)
{
	NODE_t *pdel;

	if(q->xfront == NULL) {
		return eQUEUE_EMPTY;
	}
	else {

		/* if this is the last ele */
		if (q->xfront == q->xrear) 
			q->xrear = NULL;

		pdel = q->xfront;
		q->xfront = pdel->next;
		*d = pdel->ele;
		free(pdel);
	}

	return eQUEUE_NOERR;
}

EERR_t print_q(QUEUE_t *q)
{
	NODE_t *ptmp;
	int32_t n = 1;

	printf("front %p rear %p\n", q->xfront, q->xrear);

	if(q->xfront == NULL) {
		printf("Queue is empty\n");
		return eQUEUE_EMPTY;
	}

	ptmp = q->xfront;

	while(ptmp != NULL) {
		printf("(%d): node %p node->ele %d node->next %p\n", n++, ptmp, ptmp->ele, ptmp->next);
		ptmp = ptmp->next;
	}

	return eQUEUE_NOERR;
}
