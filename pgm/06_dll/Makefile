# Special symbols
# $@ - left side of ":"
# $^ - right side of ":"
# $< - first item in depedency list
# $* -
#

# Directories
ODIR=obj
SDIR=src
IDIR=inc
SLDIR=slib
DLDIR=dlib

CFLAGS=-I$(IDIR)
CC=gcc
FLAGS=-Wall -Werror
AR=ar
AR_FLAGS=rs
LFLAGS=-fPIC

STATIC_LIB=$(SLDIR)/libdll.a
DYNAMIC_LIB=$(DLDIR)/libdll.so

exe: lib apps

lib: slib dlib

apps: app app_slib app_dlib

# source files
_APP_OBJ=app.o
_LIB_OBJ=dlist.o
_DEPS=dlist.h

# Create temporary directories
odir:
	if [ ! -d obj ]; then mkdir obj; fi;

sdir:
	if [ ! -d slib ]; then mkdir slib; fi;

ddir:
	if [ ! -d dlib ]; then mkdir dlib; fi;

# Append obj/
APP_OBJ=$(patsubst %,$(ODIR)/%,$(_APP_OBJ))
LIB_OBJ=$(patsubst %,$(ODIR)/%,$(_LIB_OBJ))

# Append slib/
SLIB_OBJ=$(patsubst %,$(SLDIR)/%,$(_LIB_OBJ))

# Append dlib/	
DLIB_OBJ=$(patsubst %,$(DLDIR)/%,$(_LIB_OBJ))

# Append include/
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

# compile: obj dir holds objects files with out fPIC
$(ODIR)/%.o: $(SDIR)/%.c $(DEPS) odir
	$(CC) -g -c -o $@ $< $(FLAGS) $(CFLAGS)

# compile: slib dir holds objects files with out fPIC
$(SLDIR)/%.o: $(SDIR)/%.c $(DEPS) sdir
	$(CC) -g -c -o $@ $< $(FLAGS) $(CFLAGS)

# compile: dlib dir holds objects files with fPIC
$(DLDIR)/%.o: $(SDIR)/%.c $(DEPS) ddir
	$(CC) -g -c -o $@ $< $(FLAGS) $(CFLAGS) $(LFLAGS)

# build app with out lib
app: $(APP_OBJ) $(LIB_OBJ)
	$(CC) -g -o $@ $^ $(FLAGS) $(CFLAGS)

# build app with static lib 
app_slib: $(APP_OBJ)
	$(CC) -g -o $@ $^ $(FLAGS) $(CFLAGS) -L$(SLDIR) -ldll

# build app with dynamic lib
app_dlib: $(APP_OBJ)
	$(CC) -g -o $@ $^ $(FLAGS) $(CFLAGS) -L$(DLDIR) -ldll

# build static library
slib: $(SLIB_OBJ)
	$(AR) $(ARFLAGS) $(STATIC_LIB) $^

# build dynamic library
dlib: $(DLIB_OBJ)
	$(CC) -shared -o $(DYNAMIC_LIB) $^

# clean
clean:
	rm -rf obj app slib dlib app_slib app_dlib 
