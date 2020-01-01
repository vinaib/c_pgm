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

	/* if list is empty */
	if(get_sll()->n_ele == 0) {
		get_sll()->head->next = pnew;
	} else {
		/* Update Sll */
		pnew->next = get_sll()->head->next;
		get_sll()->head->next = pnew;
	}

	get_sll()->n_ele += 1;

	/* if this is the first node, then update tail */
	if(get_sll()->n_ele == 1) {
		get_sll()->tail = pnew;
	}

func_exit:
	return ret;
}

bool delete_first_node()
{
	NODE_T *ptmp;

	printf("%s\n", __func__);
	if(!get_sll()) {
		printf("Initialize SLL before using it ...\n");
		goto exit_func;
	}

	if(get_sll()->n_ele == 0) {
		printf("SLL is empty\n");
		goto exit_func;
	}

	/* make head point to second node */
	ptmp = get_sll()->head->next;
	get_sll()->head->next = ptmp->next;

	get_sll()->n_ele -= 1;

exit_func:
	return 0;
}

bool insert_node_at_last(int val)
{
	printf("%s\n", __func__);

	return 0;
}

bool delete_last_node()
{
	printf("%s\n", __func__);

	return 0;
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

	while(ptmp->next != NULL)
	{
		printf("%d\n", ptmp->data);
		ptmp = ptmp->next;
	}

exit_func:
	return;
}




