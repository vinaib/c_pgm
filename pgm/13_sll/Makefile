CC=gcc
CFLAGS=-I.

DEPS=sll.o

%.o:%.c
	$(CC) -c $< -o $@ $(CFLAGS)

app_exe:$(DEPS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf app_exe *.o
