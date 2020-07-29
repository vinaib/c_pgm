#ifndef __STACK_H_
#define __STACK_H_

#include<stdint.h>

typedef struct node NODE_t;

struct node {
	void *data;
	NODE_t *next;
};

typedef struct _stack
{
	NODE_t *top;
}STACK_t;

int32_t init_stack(STACK_t *st);

int32_t free_stack(STACK_t *st);

int32_t push(STACK_t *st, void *d);

void *pop(STACK_t *st);

void *peek(STACK_t *st, uint32_t n);

NODE_t* get_top(STACK_t *st);

uint32_t isEmpty(STACK_t *st);

uint32_t isFull();

void display_stack(STACK_t *st);

#endif /* __STACK_H_ */
