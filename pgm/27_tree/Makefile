CC=gcc
CFLAGS=-I.

DEPS=app.o queue.o tree.o stack.o

%.o:%.c
	$(CC) -c $< -o $@ $(CFLAGS) -g

app_exe:$(DEPS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf app_exe *.o
