#ifndef __STACK_H_
#define __STACK_H_

#include<stdint.h>

typedef struct snode SNODE_t;

struct snode {
	void *data;
	SNODE_t *next;
};

typedef struct _stack
{
	SNODE_t *top;
}STACK_t;

int32_t init_stack(STACK_t *st);

int32_t free_stack(STACK_t *st);

int32_t push(STACK_t *st, void *d);

void *pop(STACK_t *st);

void *peek(STACK_t *st, uint32_t n);

SNODE_t* gettopOfStack(STACK_t *st);

uint32_t isStkEmpty(STACK_t *st);

uint32_t isStkFull();

void display_stack(STACK_t *st);

#endif /* __STACK_H_ */
