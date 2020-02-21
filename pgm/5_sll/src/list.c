#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<list.h>

SLL_T *init_sll()
{
	return (SLL_T *)calloc(ONE, sizeof(SLL_T));
}

SLL_T *free_sll(SLL_T *sll)
{
	if(sll!=NULL) {
		free(sll);
		sll = NULL;
	}

	return sll;
}

bool is_list_empty(SLL_T *sll)
{
	return ((sll->head == NULL) && 
			(sll->tail == NULL));
}

NODE_T* alloc_node()
{
	return (NODE_T*)calloc(ONE, sizeof(NODE_T));
}

bool insert_node_at_first(SLL_T *sll, int val)
{
	bool ret = false;
	NODE_T *pnew;

	if(sll == NULL) {
		printf("INIT SLL\n");
		goto func_exit;
	}

	pnew = alloc_node();
	if(!pnew) {
		printf("NOMEM\n");
		goto func_exit;
	}

	pnew->data = val;

	/* is list empty */
	if(is_list_empty(sll)) {
		sll->head = sll->tail = pnew;
	} else {
		/* Update sll */
		pnew->next = sll->head;
		sll->head = pnew;
	}

	sll->n_ele += 1;

	ret = true;

func_exit:
	return ret;
}

bool delete_first_node(SLL_T *sll)
{
	bool ret = false;
	NODE_T *ptmp;

	if(!sll) {
		printf("INIT SLL\n");
		goto exit_func;
	}

	/* is list empty */
	if(is_list_empty(sll)) {
		printf("EMPTY SLL\n");
		goto exit_func;
	}

	/* make head point to second node */
	ptmp = sll->head;
	sll->head = ptmp->next;

	/* When list gets empty both head and tail is null */
	if(sll->head == NULL)
		sll->tail = NULL;

	free(ptmp);

	sll->n_ele -= 1;

	ret = true;

exit_func:
	return ret;
}

bool insert_node_at_last(SLL_T *sll, int val)
{
	bool ret = false;
	NODE_T *pnew;

	if(!sll) {
		printf("INIT SLL\n");
		goto exit_func;
	}

	pnew = alloc_node();
	if(!pnew) {
		printf("NOMEM\n");
		goto exit_func;
	}
	
	pnew->data = val;

	/* is list empty */
	if(is_list_empty(sll)) {
		sll->head = sll->tail = pnew;
	} else {
		/* insert node at last and update tail */
		sll->tail->next = pnew;
		sll->tail = pnew;
	}
	
	sll->n_ele += 1;

	ret = true;

exit_func:
	return ret;
}

bool delete_last_node(SLL_T *sll)
{
	bool ret = false;
	NODE_T *pcur;
	NODE_T *pprev;

	if(!sll) {
		printf("INIT SLL\n");
		goto exit_func;
	}
	
	/* is list empty */
	if(is_list_empty(sll)) {
		printf("EMPTY SLL\n");
		goto exit_func_1;
	} else if(sll->head == sll->tail) {
		/* only one node in SLL */
		pcur = sll->tail;		// can be head too
		sll->head = sll->tail = NULL;
	} else {
		pcur = sll->head;
		pprev = sll->head;
		
		/* loop through until last node */
		while(pcur->next != NULL) {
			pprev = pcur;
			pcur = pcur->next;
		}

		/* update tail */
		sll->tail = pprev;
		pprev->next = NULL;
	}
	
	free(pcur);
	sll->n_ele -= 1;

exit_func_1:
	ret = true;

exit_func:
	return ret;
}

bool insert_node_at_idx(SLL_T *sll, unsigned int idx, int val)
{
	bool ret = false;
	NODE_T *pnew;
	NODE_T *pcur;
	NODE_T *pprev;

	if(!sll) { 
		goto exit_func;
	}

	if(idx == ZERO) {
		/* not a valid idx[1 ... n] */
		goto exit_func;
	}
	else if( (idx == ONE) ||
			 (is_list_empty(sll))) {
		insert_node_at_first(sll, val);
		goto exit_true;
	}

	pcur = pprev = sll->head;

	while((idx != ONE) && (pcur->next != NULL)) {
		pprev = pcur;
		pcur = pcur->next;	
		--idx;
	}

	if(idx != ONE) {
		insert_node_at_last(sll,val);
		goto exit_true;
	}

	/* else insert at idx */
	pnew = alloc_node();
	if(!pnew) {
		goto exit_func;
	}

	pnew->data = val;
	
	pnew->next = pcur;
	pprev->next = pnew;

	sll->n_ele += 1;
exit_true:
	ret = true;

exit_func:		
	return ret;
}

bool delete_node_at_idx(SLL_T *sll, unsigned int idx)
{
	bool ret = false;
	NODE_T *pcur;
	NODE_T *pprev;

	if(!sll) { 
		goto exit_func;
	}

	if(is_list_empty(sll)) {
		goto exit_func;
	}

	if(idx == ZERO) {
		goto exit_func;
	}
	else if(idx == ONE) {
		delete_first_node(sll);
		ret = true;
		goto exit_func;
	}

	pcur = pprev = sll->head;

	while((idx != ONE) && (pcur->next != NULL)) {
		pprev = pcur;
		pcur = pcur->next;
		--idx;
	}

	/* After loop traversal:
	 * pcur points to idx node to be deleted 
	 */
	pprev->next = pcur->next;

	/* update tail */
	if(idx != ONE) {
		sll->tail = pprev;
	}

	free(pcur);

	sll->n_ele -= 1;

exit_func:
	return ret;
}

int search_node(SLL_T *sll)
{
	printf("%s\n", __func__);

	return 0;
}

void print_sll(SLL_T *sll)
{
	NODE_T *ptmp;

	if(!sll) { 
		goto exit_func;
	}

	if(is_list_empty(sll)) {
		goto exit_func;
	}

	/* grab first element */
	ptmp = sll->head;

	while(ptmp != NULL)
	{
		printf("%d ", ptmp->data);
		ptmp = ptmp->next;
	}

	printf("\n");

exit_func:
	return;
}

void reverse_list(SLL_T *sll)
{
	NODE_T *pcur = sll->head;
	NODE_T *pnext = (sll->head)?(sll->head)->next:NULL;
	NODE_T *ptemp;

	if(sll == NULL || sll->head == NULL || sll->head->next == NULL)
		goto exit_func;

	while(pnext) {
		ptemp = pnext->next;
		pnext->next = pcur;
		pcur = pnext;
		pnext = ptemp;
	}

	(sll->head)->next = NULL;	/* last node next should be null */
	sll->tail = sll->head;
	sll->head = pcur;

exit_func:
	return;
}

void list_prefill(SLL_T *sll, int *start_val)
{
	insert_node_at_first(sll, 1);
	insert_node_at_first(sll, 2);
	insert_node_at_first(sll, 3);
	insert_node_at_last(sll, 4);
	insert_node_at_last(sll, 5);
	insert_node_at_last(sll, 6);
	insert_node_at_idx(sll, 2, 22);
	insert_node_at_idx(sll, 5, 55);
	insert_node_at_idx(sll, 8, 88);
}
