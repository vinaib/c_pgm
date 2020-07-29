#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<errno.h>

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char *s;
    int num[10] = {0};
    unsigned int len = 0;
    unsigned int i;

    s = (char *)malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    if(!s) return ENOMEM;

    s = realloc(s, strlen(s) +1);
    if(!s) return ENOMEM;

    len = strlen(s);

    if(len > 1000) {
        len = 1000;
    }

    for(i = 0; i<len; i++) {
        if(s[i] >= '0' && s[i] <= '9')
            num[s[i]-'0']++;
    }

    for(i=0; i<10; i++) {
        printf("%d ", num[i]);
    }

    printf("\n");
    
    return 0;
}
