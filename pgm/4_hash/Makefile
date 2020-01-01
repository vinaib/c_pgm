# refer for makefile: http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

# for unused variables warnings use -Wextra

# Version 5: objs files in separate folders
# source file in separate folder

CC=gcc
IDIR=include
CFLAGS=-I$(IDIR)
ODIR=obj
SDIR=src

# $(patsubst PATTERN,REPLACEMENT,TEXT)
_OBJ=func_1.o func_2.o hash.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

_DEPS=func_1.h func_2.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: tdir ht

tdir:
	if [ ! -d obj ]; then mkdir obj;fi;
	
ht: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

c:
	gcc -v -c src/hash.c $(CFLAGS)

s:
	gcc -v -S src/hash.c $(CFLAGS)

e:
	gcc -v -E src/hash.c -o hash.i

clean:
	rm -rf ht *.o *.s *.i $(ODIR)
