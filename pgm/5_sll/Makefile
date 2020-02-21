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
SLDIR=slib
DLDIR=dlib

CFLAGS=-I$(IDIR)
CC=gcc
FLAGS=-Wall -Werror
AR=ar
AR_FLAGS=rs
LFLAGS=-fPIC

STATIC_LIB=$(SLDIR)/libsll.a
DYNAMIC_LIB=$(DLDIR)/libsll.so

exe: lib apps

lib: slib dlib

apps: app app_slib app_dlib

# Create temporary directories
tdir:
	if [ ! -d obj ]; then mkdir obj; fi;
	if [ ! -d lib ]; then mkdir slib; fi;
	if [ ! -d lib ]; then mkdir dlib; fi;

# Source files
_LIB_OBJ=list.o
_APP_OBJ=app.o
_DEPS=list.h
_OBJ=$(_LIB_OBJ) $(_APP_OBJ)

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
$(ODIR)/%.o: $(SDIR)/%.c $(DEPS) tdir
	$(CC) -c -g -o $@ $< $(FLAGS) $(CFLAGS)

# compile: slib dir holds library objects files with out fpic
$(SLDIR)/%.o: $(SDIR)/%.c $(DEPS) tdir
	$(CC) -c -g -o $@ $< $(FLAGS) $(CFLAGS)

# compile: dlib dir holds library objects files with fPIC
$(DLDIR)/%.o: $(SDIR)/%.c $(DEPS) tdir
	$(CC) -c -g -o $@ $< $(FLAGS) $(CFLAGS) $(LFLAGS)

# build app with out lib
app: $(APP_OBJ) $(LIB_OBJ)
	$(CC) -o $@ $^ $(FLAGS) $(CFLAGS)

# build app with static lib
app_slib: $(APP_OBJ)
	$(CC) -o $@ $^ $(FLAGS) $(CFLAGS) -L$(SLDIR) -lsll

# build app with dynamic lib
app_dlib: $(APP_OBJ)
	$(CC) -o $@ $^ $(FLAGS) $(CFLAGS) -L$(DLDIR) -lsll

# build static library
slib: $(SLIB_OBJ)
	$(AR) $(AR_FLAGS) $(STATIC_LIB) $^

# build dynamic library
dlib: $(DLIB_OBJ)
	$(CC) -shared -o $(DYNAMIC_LIB) $^

# remove all build objs, libraries, application
clean:
	rm -rf obj app slib dlib app_slib app_dlib
