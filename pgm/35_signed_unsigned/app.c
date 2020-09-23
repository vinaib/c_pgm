#include<stdio.h>

/*
When this is compiled for some architectures (for example, for x86) the result is the one you
might intuitively expect, which is that it reports the variable c as negative, but compiling the
code on an ARM Compiler will produce code that reports c as positive, and typically a warning
will be emitted by the compiler too.

The ANSI C standard specifies a range for both:
- signed (at least -127 to +127) and 
- unsigned (at least 0 to 255) chars. 
- Simple char s are not specifically defined and it is compiler dependent whether they are signed or unsigned.

One workaround for users of GCC is to use the -fsigned-char command line switch

better practice is to write portable code by declaring char variables appropriately:
- Unsigned char must be used for accessing memory as a block of bytes or for small unsigned integers. 
- Signed char must be used for small signed integers and 
- simple char must be used only for ASCII characters and strings.

In fact, on an ARM core, it is usually better to use int s rather than char s, even for small values,
for performance reasons
*/

int main(void)
{
	char c = -1;

	if(c > 0) printf("C is positive\n");
	else printf("c is negative\n");
}
