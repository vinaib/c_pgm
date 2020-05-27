#include<stdio.h>
#include<defs.h>

emp_t E;

int main()
{
	emp_t e;

	print_emp(&e);

	print_emp(&E);

	return 0;
}

void print_emp(emp_t *pe)
{
	printf("-----------------------------------------------------------------\n");
	printf("name %s\n", pe->name);
	printf("emp_id %d\n", pe->emp_id);
	printf("designation %s\n", pe->pocc->designation);
	printf("salary %d\n", pe->pocc->salary);
	printf("-----------------------------------------------------------------\n");
}
