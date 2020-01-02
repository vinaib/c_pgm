#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<list.h>

bool init_sll()
{
	bool ret = false;

	Sll = (SLL_T*)malloc(sizeof(SLL_T));

	if(Sll != NULL) {
		Sll->head = alloc_node();
		if(Sll->head == NULL) {
			goto exit_func;
		}

		Sll->tail = alloc_node();
		if(Sll->tail == NULL) {
			goto exit_func1;
		}

		Sll->n_ele = 0;
		ret = true;

		goto success;
	}


exit_func1:
	free(Sll->head);
	Sll->head = NULL;

exit_func:
	free(Sll);
	Sll = NULL;

success:
	return ret;
}

SLL_T *get_sll()
{
	return (Sll?Sll:NULL);
}

void free_sll()
{
	if(get_sll()) {
		free(Sll->head);
		free(Sll->tail);
		free(Sll);
		Sll = NULL;
	}

	return;
}

NODE_T* alloc_node()
{
	NODE_T *pnew = NULL;

	printf("%s\n", __func__);

	pnew = (NODE_T*)malloc(sizeof(NODE_T));
	if(!pnew) {
		pnew->next = NULL;
		pnew->data = 0;
	}

	return pnew;
}

bool insert_node_at_first(int val)
{
	bool ret = false;
	NODE_T *pnew;

	printf("%s\n", __func__);

	if(!get_sll()) {
		printf("Initialize SLL before using it\n");
		goto func_exit;
	}

	pnew = alloc_node();
	if(!pnew) {
		printf("Insufficient memory ...\n");
		goto func_exit;
	}

	pnew->data = val;

	/* is list empty */
	if(get_sll()->head == NULL) {
		get_sll()->head = get_sll()->tail = pnew;
	} else {
		/* Update Sll */
		pnew->next = get_sll()->head;
		get_sll()->head = pnew;
	}

	get_sll()->n_ele += 1;

	ret = true;

func_exit:
	return ret;
}

bool delete_first_node()
{
	bool ret = false;
	NODE_T *ptmp;

	printf("%s\n", __func__);
	if(!get_sll()) {
		printf("Initialize SLL before using it ...\n");
		goto exit_func;
	}

	/* is list empty */
	if(get_sll()->head == NULL) {
		printf("SLL is empty\n");
		goto exit_func;
	}

	/* make head point to second node */
	ptmp = get_sll()->head;
	get_sll()->head = ptmp->next;

	free(ptmp);

	get_sll()->n_ele -= 1;

	ret = true;

exit_func:
	return ret;
}

bool insert_node_at_last(int val)
{
	bool ret = false;
	NODE_T *pnew;

	printf("%s\n", __func__);
	if(!get_sll()) {
		printf("Initialize SLL before using it ...\n");
		goto exit_func;
	}

	pnew = alloc_node();
	if(!pnew) {
		printf("Insufficient memory ...\n");
		goto exit_func;
	}
	
	pnew->data = val;

	/* is list empty */
	if(get_sll()->head == NULL) {
		get_sll()->head = get_sll()->tail = pnew;
	} else {
		/* insert node at last and update tail */
		get_sll()->tail->next = pnew;
		get_sll()->tail = pnew;
	}
	
	get_sll()->n_ele += 1;

	ret = true;

exit_func:
	return ret;
}

bool delete_last_node()
{
	bool ret = false;
	NODE_T *pcur;
	NODE_T *pprev;

	printf("%s\n", __func__);
	if(!get_sll()) {
		printf("Initialize SLL before using it ...\n");
		goto exit_func;
	}
	
	/* is list empty */
	if(get_sll()->head == NULL) {
		printf("list is empty no node to delete\n");
		goto exit_func_1;
	} else if(get_sll()->head == get_sll()->tail) {
		/* only one node in SLL */
		pcur = get_sll()->tail;		// can be head too
		get_sll()->head = get_sll()->tail = NULL;
		free(pcur);
	} else {
		pcur = get_sll()->head;
		pprev = get_sll()->head;
		
		/* loop through until last node */
		while(pcur->next != NULL) {
			pprev = pcur;
			pcur = pcur->next;
		}

		pprev->next = NULL;
		free(pcur);
	}
	
	get_sll()->n_ele -= 1;

exit_func_1:
	ret = true;

exit_func:
	return ret;
}

bool insert_node_at_idx(int val)
{
	printf("%s\n", __func__);

	return 0;
}

bool delete_node_at_idx()
{
	printf("%s\n", __func__);

	return 0;
}

int search_node()
{
	printf("%s\n", __func__);

	return 0;
}

void print_sll()
{
	int elements;
	NODE_T *ptmp;

	if(!get_sll()) { 
		printf("Initialize SLL before using it ...\n");
		goto exit_func;
	}

	elements = get_sll()->n_ele;

	if(elements == 0) {
		printf("SLL is empty\n");
		goto exit_func;
	}

	ptmp = get_sll()->head->next;

	if(elements == 1) {
		printf("%d \n", ptmp->data);
		goto exit_func;
	}

	while(ptmp != NULL)
	{
		printf("%d\n", ptmp->data);
		ptmp = ptmp->next;
	}

exit_func:
	return;
}




