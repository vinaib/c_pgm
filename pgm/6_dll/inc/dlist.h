#ifdef __DLIST_H_
#define __DLIST_H_

typedef struct __dnode {
	DNODE_T *left;
	DNODE_T *right;
	int val;
} DNODE_T;

typedef struct __dll {
	DNODE_T *head;
	DNODE_T *tail;
	unsigned int n_ele;
}DLL_T;

/*
 * Function: init_dll() O(1)
 * Initializes dll data struct, Should be called first before using any
 * routines.
 * Returns pointer on Success else NULL on failure
 */
DLL_T *init_dll();

/*
 * Function: alloc_node() O(1)
 * Allocate new free node and initialize next to Null
 * returns pointer to new node, else NULL on failure
 */
DNODE_T* alloc_node();

/*
 * Function: is_list_empty()
 * returns true if head and tail are NULL
 */
bool is_list_empty(DLL_T *dll);

/*
 * Function: insert_node_at_first() O(1)
 * Use this function to insert node after head. 
 */
bool insert_node_at_first(DLL_T *dll, int val);

/*
 * Function: delete_first_node() O(1)
 * Delete first node 
 * Returns true on success else false on failure
 */
bool delete_first_node(DLL_T *dll);

/*
 * Function: traverse_forward_dll(); O(n)
 * Print all element of DLL
 */
void traverse_forward_dll(DLL_T *dll);

/*
 * Function: travserse_backward_dll(); O(n)
 * Print all element of DLL
 */
void traverse_backward_dll(DLL_T *dll);

#endif /* __DLIST_H_*/
