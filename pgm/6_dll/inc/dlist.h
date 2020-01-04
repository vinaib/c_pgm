#ifdef __DLIST_H_
#define __DLIST_H_

typedef struct __dnode {
	DNODE_T *left;
	DNODE_T *right;
	int val;
} DNODE_T;

typedef struct __dll {
	DNODE_T *head;
	unsigned int n_ele;
}DLL_T;

#endif /* __DLIST_H_*/
