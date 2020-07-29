#ifndef __QUEUE_H
#define __QUEUE_H

#include<stdint.h>
#include<tree.h>
#include<stdlib.h>
#include<string.h>

#define Q_FULL 0x80001
#define Q_EMPTY 0x80002

typedef struct queue {
	uint32_t size;
	uint32_t front;
	uint32_t rear;
	NODE_t	**q;
}QUEUE_t;

int32_t init_c_queue(QUEUE_t *q, uint32_t sz);

void delete_c_queue(QUEUE_t *q);

uint32_t enqueue(QUEUE_t *q, NODE_t *n);

NODE_t* dequeue(QUEUE_t *q);

int32_t isEmpty(QUEUE_t *q);

int32_t isFull(QUEUE_t *q);

void display(QUEUE_t *q);

#endif /* __QUEUE_H */
