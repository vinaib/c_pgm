#ifndef __LIST_H
#define __LIST_H

/* SLL NODE */
typedef struct node{
	struct node* next;
	int data;
}NODE_T;

bool insert_node();
bool delete_node();
bool search_node();
bool alloc_node();
bool insert_node_at_last();
bool delete_last_node();

#endif
