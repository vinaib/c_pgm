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
	if(dll->head->right == NULL) 
		dll->tail->right = pnew;

	pnew->right = dll->head->right;

exit_func:
	return ret;
}
