CC=gcc
CFLAGS=-I.

DEPS=app.o

%.o:%.c
	$(CC) -g -c $< -o $@ $(CFLAGS)

app_exe:$(DEPS)
	$(CC) -g -o $@ $^ $(CFLAGS)

clean:
	rm -rf app_exe *.o
