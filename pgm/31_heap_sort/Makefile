CC=gcc
CFLAGS=-I.

INC=heap_sort.h
DEPS=app.o heap_sort.o

%.o:%.c
	$(CC) -g -c $< -o $@ $(CFLAGS)

app_exe:$(DEPS)
	$(CC) -g -o $@ $^ $(CFLAGS)

clean:
	rm -rf app_exe *.o
