CC=gcc
CFLAGS=-I.

DEPS=app.o

all: app_exe pre_process

%.o:%.c
	$(CC) -c $< -o $@ $(CFLAGS) -g

app_exe:$(DEPS)
	$(CC) -o $@ $^ $(CFLAGS)

pre_process: 
	$(CC) -E app.c -o app.i

clean:
	rm -rf app_exe *.o *.i
