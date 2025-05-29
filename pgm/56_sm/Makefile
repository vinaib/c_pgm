#make with no argumens executed first rule in the file
#make knows the rule needs to be executed if any of those file changes (ALL: eg.c state.c)
#By putting the object files in the dependency list and in the rule(ALL: eg.o state.o)
##make knows it must first compile the .c versions individually and build the executable 
#if you make change to .h file, make will not compile .c files event though they need to be. In order to fix this we need to tell make that all 
## .c files depend on certian .h files.
#$@ $^ are the special macros, which are left and right sides of :. (i.e. $@ = sm and $^ = $(OBJ)
#$< is the first item in the dependency list

CC=gcc
CFLASG=-I.
DEPS=state.h event.h sm.h
OBJ=eg.o state.o sm.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

sm: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf sm
	rm -rf *.o
