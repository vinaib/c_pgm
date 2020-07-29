#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<errno.h>

void line_to_words(void)
{
	    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]s", s);
    s = realloc(s, strlen(s) + 1);
    //Write your logic to print the tokens of the sentence here.

    for (int i=0; i < strlen(s); i++) {
        if(s[i] != ' ')
            printf("%c", s[i]);
        else
            printf("\n");
    }
	printf("\n");

#if 0
	char c[] = "C pgm is fun";
	printf("len of c %ld\n", strlen(c));
	printf("space %d \\0 %d\n", ' ', '\0');
#endif

	free(s);
}
