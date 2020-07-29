#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

/* typedef of NEXT node in linked list struct */
typedef struct node NODE_t;

struct node {
	int32_t data;
	NODE_t *next;
};

NODE_t *alloc_node(void)
{
	NODE_t *xnew;

	xnew = (NODE_t *)malloc(sizeof(NODE_t));

	memset((void *)xnew, 0, sizeof(NODE_t));

	return xnew;
}

int main(void)
{
	NODE_t *xnew;

	xnew = alloc_node();
	if(xnew == NULL) {
		printf("MEMFULL\n");
	}
	else {
		free(xnew);
	}

}
