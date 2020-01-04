#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<list.h>

bool init_sll()
{
	bool ret = false;

	Sll = (SLL_T*)malloc(sizeof(SLL_T));

	if(Sll != NULL) {
		Sll->head = NULL;
		Sll->tail = NULL;
		Sll->n_ele = 0;

		ret = true;

		goto success;
	}

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
		free(Sll);
	}

	return;
}

bool is_list_empty()
{
	return ((get_sll()->head == NULL) && 
			(get_sll()->tail == NULL));
}

NODE_T* alloc_node()
{
	return (NODE_T*)calloc(ONE_MEMBER, sizeof(NODE_T));
}

bool insert_node_at_first(int val)
{
	bool ret = false;
	NODE_T *pnew;

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
	if(is_list_empty()) {
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

	if(!get_sll()) {
		printf("Initialize SLL before using it ...\n");
		goto exit_func;
	}

	/* is list empty */
	if(is_list_empty()) {
		printf("SLL is empty\n");
		goto exit_func;
	}

	/* make head point to second node */
	ptmp = get_sll()->head;
	get_sll()->head = ptmp->next;

	/* When list gets empty both head and tail is null */
	if(get_sll()->head == NULL)
		get_sll()->tail = NULL;

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
	if(is_list_empty()) {
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

	if(!get_sll()) {
		printf("Initialize SLL before using it ...\n");
		goto exit_func;
	}
	
	/* is list empty */
	if(is_list_empty()) {
		printf("SLL is empty\n");
		goto exit_func_1;
	} else if(get_sll()->head == get_sll()->tail) {
		/* only one node in SLL */
		pcur = get_sll()->tail;		// can be head too
		get_sll()->head = get_sll()->tail = NULL;
	} else {
		pcur = get_sll()->head;
		pprev = get_sll()->head;
		
		/* loop through until last node */
		while(pcur->next != NULL) {
			pprev = pcur;
			pcur = pcur->next;
		}

		/* update tail */
		get_sll()->tail = pprev;
		pprev->next = NULL;
	}
	
	free(pcur);
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
	NODE_T *ptmp;

	if(!get_sll()) { 
		printf("Initialize SLL before using it ...\n");
		goto exit_func;
	}

	if(is_list_empty()) {
		printf("SLL is empty\n");
		goto exit_func;
	}

	/* grab first element */
	ptmp = get_sll()->head;

	while(ptmp != NULL)
	{
		printf("%d\n", ptmp->data);
		ptmp = ptmp->next;
	}

exit_func:
	return;
}




