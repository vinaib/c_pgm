CC=gcc
CFLAGS=-I.

DEPS=app.o stack.o

%.o:%.c
	$(CC) -c $< -o $@ $(CFLAGS) -g

app_exe:$(DEPS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf app_exe *.o
