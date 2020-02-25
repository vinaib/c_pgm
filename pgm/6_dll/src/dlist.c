#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#include<dlist.h>

#define ZERO 0
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
	return ((dll->head == NULL) && 
			(dll->tail == NULL));
}

bool insert_node_at_first(DLL_T *dll, void *data)
{
	bool ret = false;
	DNODE_T *pnew;

	if(dll == NULL) 
		goto exit_func;

	pnew = alloc_node();
	if(pnew == NULL)
		goto exit_func;

	pnew->data = data;

	/* very first node */
	if(dll->head == NULL) {
		printf("Very first node\n");
		dll->head = dll->tail = pnew;
	} else {
		pnew->right = dll->head;
		(dll->head)->left = pnew;
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

	/* check for last item */
	if(pdel->right != NULL)
		(pdel->right)->left = NULL;
	else
		dll->tail = dll->head = NULL;

	/* last item will assign null to head */
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
		printf("data %p\n", ptemp->data);
		ptemp=ptemp->right;
	}

exit_func:
	return;
}

void traverse_backward_dll(DLL_T *dll)
{
	DNODE_T *ptemp;

	if(dll == NULL)
		goto exit_func;

	if(dll->head == NULL)
		goto exit_func;

	ptemp = dll->tail;

	while(ptemp != NULL) {
		printf("data %p\n", ptemp->data);
		ptemp=ptemp->left;
	}

exit_func:
	return;
}

bool insert_node_at_last(DLL_T *dll, void *data)
{
	bool ret = false;
	DNODE_T *pnew;

	if(dll == NULL) 
		goto exit_func;

	pnew = alloc_node();
	if(pnew == NULL)
		goto exit_func;
	
	pnew->data = data;

	/*no elements*/
	if(dll->tail == NULL && dll->head == NULL) {
		dll->tail = dll->head = pnew;
	}else {
		(dll->tail)->right = pnew;
		pnew->left = dll->tail;
		dll->tail = pnew;
	}

	ret = true;

exit_func:
	return ret;
}

bool delete_last_node(DLL_T *dll)
{
	bool ret = false;
	DNODE_T *pdel;

	if(dll == NULL)
		goto exit_func;

	if(is_list_empty(dll)) 
		goto exit_func;

	pdel = dll->tail;

	if(pdel->left != NULL)
		(pdel->left)->right = NULL;
	else
		dll->tail = dll->head = NULL;

	dll->tail = pdel->left;

	free(pdel);

	ret = true;

exit_func:
	return ret;
}

bool insert_node_at_idx(DLL_T *dll, int idx, void *data)
{
	bool ret = false;
	DNODE_T *pnew;
	DNODE_T *pcur = dll->head;

	if(dll == NULL)
		goto exit_func;

	if(idx == ZERO || idx == ONE || is_list_empty(dll)) {
		insert_node_at_first(dll, data);
		goto exit_true;
	}

	while((idx != ONE) && (pcur != NULL)) { 
		--idx; pcur = pcur->right;
	}

	if(idx != ONE) {
		insert_node_at_last(dll, data);
		goto exit_true;
	}

	/* insert at idx */
	if((pnew = alloc_node()) == NULL)
		goto exit_func;
	
	pnew->data = data;

	pnew->right = pcur;
	pnew->left = pcur->left;
	(pcur->left)->right=pnew;
	pcur->left = pnew;

exit_true:
	ret = true;
exit_func:
	return ret;
}

bool delete_node_at_idx(DLL_T *dll, int idx)
{
	bool ret = false;
	DNODE_T *pcur = dll->head;

	if(dll == NULL)
		goto exit_func;

	if(is_list_empty(dll)) goto exit_func;

	if(idx == ZERO || idx == ONE) {
		delete_first_node(dll);
		goto exit_true;
	}

	while((idx != ONE) && (pcur != NULL)) {
		--idx; pcur = pcur->right;
	}

	if(idx != ONE) {
		delete_last_node(dll);
		goto exit_true;
	}

	(pcur->right)->left = pcur->left;
	pcur->left = pcur->right;

	free(pcur);

exit_true:
	ret = true;
exit_func:
	return ret;
}
