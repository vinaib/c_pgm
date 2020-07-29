#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

uint8_t *stringcat (uint8_t *str1, uint8_t *str2)
{
	uint16_t i,k = 0;
	uint8_t *res, *temp, *temp1;
	uint8_t len = 25;

	if(!str1) 
	 return NULL;
	 
	if(!str2)
	  return NULL;

	temp = strstr(str1, " ");
	len = (uint8_t)((uint8_t *)temp - (uint8_t *)str1);
	
	temp = strstr(str2, " ");
	len++;
	temp++;
	
	//As second word was last there is no space.
	//temp1 = strstr(temp, " "); 

	//len += (int)((char *)temp1 - (char *)temp);
	len += strlen(temp);

	res = (uint8_t *)malloc(len);  
	
	/* extract first word from str1 */
	for(i=0; str1[i] != ' '; i++) {
		res[k++] = str1[i];
	}
	
	/* space */
	res[k++] = ' ';
	
	/* skip first word */
	for(i=0; str2[i] != ' '; i++);
		
	i++;

	/* extract second word from str2 */
	for(; str2[i] != ' ' && str2[i] != '\0' ; i++) {
		res[k++] = str2[i];
	}

	res[k] = '\0';
	
	return res;
}

#define FIRST_WORD 1
#ifdef NWORD_USING_STRTOK
uint8_t *find_n_word(uint8_t *str, uint8_t nword)
{
	uint8_t *temp;

	temp = strtok(str, " ");

	if(nword == FIRST_WORD)
		return temp;
	else {
		uint8_t i = 2;

		while(i <= nword) {
			i++;
			temp = strtok(NULL, " ");
		}
	}

	return temp;
}
#else
uint8_t *find_n_word(uint8_t *str, uint8_t nword)
{
	//uint8_t str1[] = "1POLY 2COM 3asdk 4akdjfkdjfi 5skdjfkdsi 6kjkui 7kjsdfj";
	uint8_t *tmp;
	uint32_t i=0,j=0;
	uint32_t start = 0, end = 0;
	uint32_t len = 0;

	if(nword == 0) 
		return NULL;

	if(str == NULL) 
		return NULL;

	while(nword--) {
		start = i;
		while(str[i] != ' ' && str[i] != '\0' && str[i] != '\n') { i++; }
		end = i;
		i++; //skip space
	}

	if(end > start) {
		len = end - start;

		tmp = (uint8_t *)malloc(sizeof(char) * (len+1));
		if(tmp == NULL)  printf("Malloc failed\n");

		memset(tmp, 0, len);
		i = start;
		for(j=0; j<len; j++,i++) {
			*(tmp+j) = *(str+i);
		}
		*(tmp+j)='\0';
		
		return tmp;
	}
	else {
		return NULL;
	}
}
#endif

void find_duplicates(uint8_t *str, int n_len)
{
	uint32_t h = 0, x = 1;

	for(uint32_t i=0; i<n_len; i++) {
		x = 1;

		x = x << (str[i] - 'a');

		if((x & h)) 
			printf("duplicates %c\n", str[i]);
		else
			h |= x;
	}
}

void scpy(uint8_t *d, uint8_t *s)
{
	//while( (*d++ = *s++) != '\0');
	while(*d++ = *s++);
}

uint8_t scmp(uint8_t *f, uint8_t *s)
{
	for(;*f == *s ; f++, s++)
		if(*f == '\0') return 0;

	return *f - *s;
}

void sncpy(uint8_t *d, uint8_t *s, uint32_t len)
{
	if(len <= 0) return;

	while(len--) {
		*d++ = *s++;
	}

	*d++='\0';
}

uint32_t slen(uint8_t *str) 
{
	uint32_t i = 0;

	while(*(str+i) != '\0') i++;

	return i;
}

uint32_t ati(uint8_t *str)
{
	uint32_t i = 0;
	uint32_t n = 0;

	while(*(str+i) != '\0' && *(str+i) != '\n') {
		if(*(str+i) >= '0' && *(str+i) <= '9') {
			n = (n*10) + *(str+i) - '0';
		}
		i++;
	}

	return n;
}

uint32_t ith(uint32_t d)
{
	uint32_t h = 0, i = 0, n = 0;

	while(d != 0)
	{
		h = d % 16;
		d = d / 16;
		printf("h%d d%d\n", h, d);
		if(i++==0) 
			n = h;
		else
			n += h * (i++ * 10);
		printf("n%d\n", n);
	}

	return n;
}

int main(void)
{
	uint8_t str1[] = "1POLY 2COM 3asdk 4akdjfkdjfi 5skdjfkdsi 6kjkui 7kjsdfj";
	uint8_t str2[] = "PLT RONIC";
	uint8_t str3[] = "finding";

	uint8_t *res;

	uint8_t str4[20];

	//res = stringcat(str1, str2);

	printf("str1[%ld:%d] %s\n", strlen(str1), slen(str1), str1);
	printf("str2[%ld:%d] %s\n", strlen(str2), slen(str2), str2);
	printf("str3[%ld:%d] %s\n", strlen(str3), slen(str3), str3);
	printf("ati %u\n", ati(str1));
	printf("ati %u\n", ati(str2));

	printf("ith %x\n", ith(100));

	res = find_n_word(str1, 2);
	if(res) {
		printf("%s\n", res);
		free(res);
	}

	res = find_n_word(str1, 4);
	if(res) {
		printf("%s\n", res);
		free(res);
	}

	res = find_n_word(str1, 7);
	if(res) {
		printf("%s\n", res);
		free(res);
	}

	res = find_n_word(str1, 8);
	if(res) {
		printf("%s\n", res);
		free(res);
	}

	find_duplicates(str3, strlen(str3));
	find_duplicates(str2, strlen(str2));
	//printf("res %s\n", res);

	//free(res);
	//scpy(str4, str1);
	sncpy(str4, str1, 16);
	printf("sncpy %s\n", str4);

	sncpy(str4, str1, 2);
	printf("sncpy %s\n", str4);

	sncpy(str4, str1, 20);
	printf("sncpy %s\n", str4);

	printf("scmp %s\n", (scmp(str4, str2)?"Not Equal":"Equal"));
	printf("scmp %s\n", (scmp(str4, str1)?"Not Equal":"Equal"));
	printf("scmp %s\n", (scmp(str1, str1)?"Not Equal":"Equal"));
}
