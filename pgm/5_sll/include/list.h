#ifndef __LIST_H
#define __LIST_H

#define ZERO 0
#define ONE 1

/* SLL NODE */
typedef struct node {
	struct node* next;
	int data;
}NODE_T;

typedef struct _sll {
	NODE_T *head;
	NODE_T *tail;
	int n_ele;
}SLL_T;


/*
 * Function: init_sll()
 * Initializes sll data struct, Should be called first before using any
 * routines.
 * Returns pointer on Success else NULL on failure
 */
SLL_T *init_sll();

/*
 * Function: is_list_empty()
 * returns true if head and tail are NULL
 */
bool is_list_empty(SLL_T *sll);

/*
 * Function: insert_node_at_first()
 * Use this function to insert node after head. Update the head pointer to point
 * this node and increase n_ele by 1
 */
bool insert_node_at_first(SLL_T *sll, int val);

/*
 * Function: delete_first_node()
 * Delete first node and update the head to point to next node and decrement
 * n_ele by 1.
 * Returns true on success else false on failure
 */
bool delete_first_node(SLL_T *sll);

/*
 * Function: insert_node_at_last()
 * Insert node at last and update the tail pointer and increment n_ele by 1.
 * Returns 
 */
bool insert_node_at_last(SLL_T *sll, int val);

/*
 * Function: delete_last_node()
 * deletes last node by pointing tail to previous last but one node and
 * decrement n_ele by 1.
 *
 * Returns true on success else false on failure
 */
bool delete_last_node(SLL_T *sll);

/*
 * Function: insert_node_at_idx()
 * Insert node at given index/location and update the n_ele
 *
 * Returns true on success else false on failure
 */
bool insert_node_at_idx(SLL_T *sll, unsigned int idx, int val);

/*
 * Function: delete_node_at_idx
 * Delete node at given index, and decrement n_ele by 1.
 * Returns true on success else false on failure
 */
bool delete_node_at_idx(SLL_T *sll, unsigned int idx);

/*
 * Function: search_node()
 * search node by given value
 *
 * Returns: index/postion of the given value in SLL else 0 on failure.
 */
int search_node(SLL_T *sll);

/* 
 * Function: print_sll();
 * Print all element of SLL
 */
void print_sll(SLL_T *sll);

/*
 * Function: alloc_node()
 * Allocate new free node and initialize next to Null
 * returns pointer to new node, else NULL on failure
 */
NODE_T* alloc_node();

/*
 * Function free_sll()
 * Should be called as part of clean up
 */
SLL_T *free_sll(SLL_T *sll);

#endif
