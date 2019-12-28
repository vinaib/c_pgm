# refer for makefile: http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

# for unused variables warnings use -Wextra

#version 2
CC=gcc
CFLAGS=-I.
IDIR=../include
ODIR=../obj
# $(patsubst PATTERN,REPLACEMENT,TEXT)
_OBJ=func_1.o func_2.o hash.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))
_DEPS=func_1.h func_2.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

#vinai: ht

# version 1: specifying "c files" in dependency list will compile "c files
# always. 
# -I. in gcc command will make "c files" to include local header files in
# angular brackets.
#exe: func_1.c func_2.c hash.c 
#	gcc -Wall -Wextra -Werror hash.c func_1.c func_2.c -o ht -I.

# version 2: specifying object files in dependency list will compile c files
# only if there is any modification in source files, else it will use previously
# compiled object file.
# CC, CFLAGS
#exe: func_1.o func_2.o hash.o
#	$(CC) -Wall -Wextra -Werror hash.o func_1.o func_2.o -o ht $(CFLAGS)


# version 3: creating dependency on include files. If include file is modified
# then source files which includes modified header file is forced to recompile
# DEPS is macro, contains list of all header files.
# Define rule that applies to all files ending .o suffix (%.o). The rule says
# that the .o file depends upon the .c version of the file and the .h files
# included in the DEPS macro (%.o: %.c $(DEPS))
#%.o: %.c $(DEPS)
# wildcard %: matching any number of characters with in a word.
#	$(CC) -c -o $@ $< $(CFLAGS)

#exe: func_1.o func_2.o hash.o	
#	$(CC) -Wall -Wextra -Werror hash.o func_1.o func_2.o -o ht $(CFLAGS)


# version 4: Use of special macrso $@ and $^
# SPECIAL MACROS:
# $< is the first item in the dependencies list, which is $(DEPS)
# $@ and $^: which are the left and right sides of the :
#%.o: %.c $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS)

#ht: $(OBJ)
#	$(CC) -o $@ $^ $(CFLAGS)
	
# Version 5: objs, header files in separate folders


$(ODIR)/%.o: %.c $(DEPS)
	echo "vinai";
	echo $(OBJ)
	$(CC) -v -c -o $@ $< $(CFLAGS)

#ht: $(OBJ)
#	$(CC) -v -o $@ $^ $(CFLAGS)

c:
	gcc -v -c hash.c

s:
	gcc -v -S hash.c

e:
	gcc -v -E hash.c -o hash.i

clean:
	rm -rf ht *.o *.s *.i
