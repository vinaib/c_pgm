#include<stdio.h>
#include<stddef.h>
#include<stdint.h>

struct person {
	uint8_t *name;
	uint32_t age;
};

int main(void)
{
	struct person p;

	/* size_t offsetof(type, member); */
	printf("offset of name %ld\n", offsetof(struct person, name));
	printf("offset of age %ld\n", offsetof(struct person, age));

	typeof

}
