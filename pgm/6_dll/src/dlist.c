#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#include<dlist.h>

#define ONE 1

DLL_T *init_dll()
{
	return (DLL_T*)calloc(ONE, sizeof(DLL_T));
}


DNODE_T* alloc_node()
{
	return (DNODE_T*)calloc(ONE, sizeof(DNODE_T));
}


bool is_list_empty(DLL_T *dll)
{
	return ((dll->head->right == NULL) && (dll->tail->left == NULL));
}

bool insert_node_at_first(DLL_T *dll, int val)
{
	bool ret = false;
	DNODE_T *pnew;

	if(dll == NULL) 
		goto exit_func;

	pnew = alloc_node();
	if(pnew == NULL)
		goto exit_func;

	pnew->val = val;

	/* very first node */
	if(dll->head == NULL) {
		printf("Very first node\n");
		dll->head = pnew;
		dll->tail = pnew;
	} else {
		pnew->right = dll->head;
		pnew->left = NULL;
		dll->head = pnew;
	}

	ret = true;

exit_func:
	return ret;
}


bool delete_first_node(DLL_T *dll)
{
	bool ret = false;
	DNODE_T *pdel;


	if(dll == NULL)
		goto exit_func;

	/* no elements */
	if(dll->head == NULL)
		goto exit_func;

	pdel = dll->head;

	(pdel->right)->left = NULL;
	dll->head = pdel->right;

	free(pdel);

	ret = true;		
exit_func:
	return ret;
}


void traverse_forward_dll(DLL_T *dll)
{
	DNODE_T *ptemp;

	if(dll == NULL)
		goto exit_func;

	if(dll->head == NULL)
		goto exit_func;

	ptemp = dll->head;

	while(ptemp != NULL) {
		printf("data %d\n", ptemp->val);
		ptemp=ptemp->right;
	}

exit_func:
	return;
}
