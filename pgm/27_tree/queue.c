#include<queue.h>
#include<stdio.h>

int32_t init_c_queue(QUEUE_t *q, uint32_t sz)
{
	int32_t ret = 0;

	q->size = sz;
	q->front = q->rear = 0;
	q->q = (NODE_t**)calloc(sz, sizeof(NODE_t *));
	if(q->q == NULL)
		ret = -1;
	
	return ret;
}

void delete_c_queue(QUEUE_t *q)
{
	q->size = 0;
	q->front = q->rear = 0;
	if(q->q != NULL) 
		free(q->q);
}

uint32_t enqueue(QUEUE_t *q, NODE_t *n)
{
	if(((q->rear + 1) % q->size) == q->front)
		return (uint32_t)Q_FULL;
	else {
		q->rear = (q->rear + 1) % q->size;
		q->q[q->rear] = n;
		return q->rear;
	}
}

NODE_t* dequeue(QUEUE_t *q)
{
	NODE_t *ret;

	if( q->front == q->rear)
		return (NODE_t *)Q_EMPTY;
	else
	{
		q->front = (q->front + 1) % q->size;
		ret = (void *)q->q[q->front];
		q->q[q->front] = NULL;
		return ret;
	}
}

int32_t isEmpty(QUEUE_t *q)
{
	return (q->front == q->rear);
}

int32_t isFull(QUEUE_t *q)
{
	return ((q->rear + 1) % q->size == q->front);
}

void display(QUEUE_t *q)
{
	int32_t i;

	printf("--------------------------------------------------------------\n");
	printf("Queue: size %d\tfront %d\trear %d\n", \
			q->size, q->front, q->rear);
	printf("--------------------------------------------------------------\n");

	for(i=0; i<q->size; i++)
	{	
		printf("%d:%20p  ", i, q->q[i]);
		if(!((i+1)%2)) 
			printf("\n");
	}
	printf("\n--------------------------------------------------------------\n");

	return;
}
