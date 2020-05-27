#ifndef __DEFS_H
#define __DEFS_H

/* Forward declaration: Instructs the compiler not to throw error,
 * It only works for pointer usage of structure not if it is used 
 * as complete usage.
 */
typedef struct _occ occ_t;

/* occ_t occ is complete usage 
 * occ_t *pocc: then it is pointer usage
 */
typedef struct _emp {
	char name[32];
	unsigned int emp_id;
	occ_t *pocc;			/* no error, for pointer usage*/
	//occ_t occ;			/* throws error for complete usage */
}emp_t;

typedef struct _occ {
	char designation[32];
	unsigned int salary;
}occ_t;

void print_emp(emp_t *);
//void print_size(emp_t *);

#endif /*__DEFS_H*/
