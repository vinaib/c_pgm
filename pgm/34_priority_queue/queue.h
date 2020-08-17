/* Linked list representation of queue */
#include<stdint.h>
typedef enum err {
	eQUEUE_FULL 	= -1,
	eQUEUE_EMPTY 	= -2,
	eQUEUE_NOMEM	= -3,
	eQUEUE_NOERR	= 0,		
}EERR_t;

typedef struct node {
	struct node *next;
	int32_t ele;
}NODE_t;

typedef struct queue {
	NODE_t *xfront;
	NODE_t *xrear;
}QUEUE_t;

EERR_t init_queue(QUEUE_t *q);

EERR_t enqueue(QUEUE_t *q, int32_t i);

EERR_t dequeue(QUEUE_t *q, int32_t *d);

EERR_t print_q(QUEUE_t *q);
