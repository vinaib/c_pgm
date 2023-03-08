/* Task

Your task is to take two numbers of int data type, two numbers of float data type as input and output their sum:

Declare  variables: two of type int and two of type float.
Read  lines of input from stdin (according to the sequence given in the 'Input Format' section below) and initialize your  variables.
Use the  and  operator to perform the following operations:
Print the sum and difference of two int variable on a new line.
Print the sum and difference of two float variable rounded to one decimal place on a new line.
Input Format

The first line contains two integers.
The second line contains two floating point numbers.

Constraints

 integer variables 
 float variables 
Output Format

Print the sum and difference of both integers separated by a space on the first line, and the sum and difference of both float (scaled to  decimal place) separated by a space on the second line.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int ia, ib;
    float fa,fb;

    scanf("%d %d", &ia, &ib);
    scanf("%f %f", &fa, &fb);


    if( ( (ia < 1) && (ia > 10000) ) || ((ib < 1) && (ib > 10000) ) )
        goto EXIT_PGM;

    if( ( (fa < 1) && (fa > 10000) ) || ((fb < 1) && (fb > 10000) ) )
        goto EXIT_PGM;

    printf("%d %d\n", (ia + ib), (ia - ib));
    printf("%.1f %.1f\n", (fa + fb), (fa - fb));

    EXIT_PGM:
    return 0;
}