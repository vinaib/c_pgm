# for unused variables warnings use -Wextra
# -v: print the commands executed to run the stages 
#
# -fPIC: Create position independent code, While creating shared libraries
# position independent code should be produced. This helps the shared library to
# get loaded at any address instead of some fixed address. For this -fPIC option
# is used
#
# -D: Use compile time macros using -D option
#
# -Werror: Convert warnings into errors
#
# make with no arguments, executes first rule in the file, it need not to be a
# "all" or "default"


all:
	gcc -Wall -Wextra -Werror rev_input.c -v -o reverse

# compile only, created rev_input.o	
c:
	gcc -v -c rev_input.c

# assemble only, creares rev_input.s
s:
	gcc -v -S rev_input.c

# Preprocessing, processing stage is output to standard output. It can be
# redirected to file.
e:
	gcc -v -E rev_input.c > input.i

clean:
	rm reverse *.o *.s input.i
