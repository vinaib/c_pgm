CC=gcc
CFLAGS=-I.

DEPS=queue.h
SRCS=app.o queue.o

%.o:%.c $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS) -g

app_exe:$(SRCS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf app_exe *.o
