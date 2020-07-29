#ifndef __TREE_H
#define __TREE_H

#include<stdint.h>

#define MAGIC_ROOT_DATA 0x20002
#define Q_SIZE			10

typedef struct node NODE_t;

struct node {
	NODE_t *lchild;
	int32_t data;
	NODE_t *rchild;
};

void create_tree(NODE_t *tree);
void pre_order(NODE_t *tree);
void in_order(NODE_t *tree);
void post_order(NODE_t *tree);
void pre_order_iterative(NODE_t *xtree);
void in_order_iterative(NODE_t *xtree);
void level_order_traversal(NODE_t *xtree);

#endif /* __TREE_H */
