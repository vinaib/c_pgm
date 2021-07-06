CC=gcc
CFLAGS=-I.
FLAGS=-lpthread
DEBUG=-g

DEPS=app.o continuous.o discrete.o

# with out following rule, Makefile still compile each files individually.
# %.o:%.c
# 	$(CC) -c $< -o $@ $(CFLAGS)
# following is the output after removing below rule
# gcc -I.   -c -o app.o app.c
# gcc -I.   -c -o second.o second.c
# gcc -o app_exe app.o second.o -I.

# Having below rule, helps us to customize things,
# %.o:%.c
# 	$(CC) -c $< -o $@ $(CFLAGS)
# following following is the output after having this rule
# gcc -c app.c -o app.o -I.
# gcc -c second.c -o second.o -I.
# gcc -o app_exe app.o second.o -I.

%.o:%.c
	$(CC) -c $< -o $@ $(CFLAGS) $(FLAGS) $(DEBUG)

app_exe:$(DEPS)
	$(CC) -o $@ $^ $(CFLAGS) -lm $(FLAGS) $(DEBUG)

clean:
	rm -rf app_exe *.o
