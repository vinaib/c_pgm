/*Objective

This challenge will help you to learn how to take a character, a string and a sentence as input in C.

To take a single character  as input, you can use scanf("%c", &ch ); and printf("%c", ch) writes a character specified by the argument char to stdout

char ch;
scanf("%c", &ch);
printf("%c", ch);
This piece of code prints the character .

You can take a string as input in C using scanf(“%s”, s). But, it accepts string only until it finds the first space.

In order to take a line as input, you can use scanf("%[^\n]%*c", s); where  is defined as char s[MAX_LEN] where  is the maximum size of . Here, [] is the scanset character. ^\n stands for taking input until a newline isn't encountered. Then, with this %*c, it reads the newline character and here, the used * indicates that this newline character is discarded.

Note: After inputting the character and the string, inputting the sentence by the above mentioned statement won't work. This is because, at the end of each line, a new line character (\n) is present. So, the statement: scanf("%[^\n]%*c", s); will not work because the last statement will read a newline character from the previous line. This can be handled in a variety of ways and one of them being: scanf("\n"); before the last statement.

Task

You have to print the character, , in the first line. Then print  in next line. In the last line print the sentence, .
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_LINE_LEN 80
#define MAX_STR_LEN 26

int main() 
{
    char ch;
    char str[MAX_STR_LEN];
    char line[MAX_LINE_LEN];

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    scanf("%c", &ch);
    scanf("%s", str);
    scanf("\n");
    scanf("%[^\n]%*c", line);

    printf("%c\n%s\n%s\n", ch, str, line);
    return 0;
}