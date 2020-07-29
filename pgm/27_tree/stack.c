#include<stack.h>
#include<stdio.h>
#include<stdlib.h>

/* expects valid st address */
int32_t init_stack(STACK_t *st)
{
	int32_t ret = 0;

	if(st == NULL) {
		ret = -1;
		goto exit_1;
	}

	/* stack initial condition */
	st->top = NULL;

exit_1:
	return ret;
}

int32_t free_stack(STACK_t *st)
{
	int32_t ret = 0;
	uint64_t data;

	if(st->top != NULL)
	{
		/* traverse list and free each node and finally
		 * delete st->stk
		 */
		SNODE_t *del;
		
		printf("free_stack: ");
		while(st->top != NULL) {
			data = (uint64_t)pop(st);
			printf("%ld ", data);
		}
		
		printf("\n");
	}

	return ret;
}


int32_t push(STACK_t *st, void *d)
{
	int32_t ret = 0;

	SNODE_t *new;

	new = (SNODE_t *)calloc(1, sizeof(SNODE_t));
	if(new == NULL) {
		ret = -1;
		goto exit_1;
	} else {
		new->data = d;
		new->next = st->top;
		st->top = new;
	}

exit_1:
	return ret;
}


void *pop(STACK_t *st)
{
	SNODE_t *del;
	void *data;

	if(st->top != NULL) {
		del = st->top;
		data = del->data;
		st->top = del->next;
		free(del);
	} else {
		data = NULL;
	}

	return (void *)data;
}


void *peek(STACK_t *st, uint32_t n)
{
	if(isStkEmpty(st))
	{
		return (void *)NULL;
	}

	SNODE_t *cur;

	cur = st->top;

	while(n && cur != NULL)
	{
		cur = cur->next;
		--n;
	}

	return cur->data;
}


SNODE_t *gettopOfStack(STACK_t *st)
{
	return (st->top);
}


uint32_t isStkEmpty(STACK_t *st)
{
	return (st->top == NULL);
}


uint32_t isStkFull()
{
	int32_t ret = 0;

	SNODE_t *new;

	/* if unable to allocate memory treat this 
	 * case as full case.
	 */
	new = (SNODE_t *)calloc(1, sizeof(SNODE_t));
	if(new == NULL)
		ret = -1;
	else
		free(new);

	return ret;
}

void display_stack(STACK_t *st)
{
	SNODE_t *tmp = st->top;

	while(tmp != NULL) {
		printf("%p ", tmp->data);
		tmp = tmp->next;
	}
}
