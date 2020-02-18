# Special symbols
# $@ - left side of ":"
# $^ - right side of ":"
# $< - first item in depedency list
# $* -
#

# Directories
ODIR=obj
SDIR=src
IDIR=include

CFLAGS=-I$(IDIR)
CC=gcc
FLAGS=-Wall -Werror

exe: tdir app

# Create temporary directories
tdir:
	if [ ! -d obj ]; then mkdir obj; fi;

_OBJ=dlist.o app.o
_DEPS=dlist.h

# Append obj/
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

# Append include/
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

# compile
$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -g -c -o $@ $< $(FLAGS) $(CFLAGS)

app: $(OBJ)
	$(CC) -g -o $@ $^ $(FLAGS) $(CFLAGS)

# clean
clean:
	rm -rf obj app
