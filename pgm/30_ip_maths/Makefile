CC=gcc
CFLAGS=-I.

INC=ip.h
DEPS=app.o ip.o

%.o:%.c
	$(CC) -g -c $< -o $@ $(CFLAGS)

app_exe:$(DEPS)
	$(CC) -g -o $@ $^ $(CFLAGS)

clean:
	rm -rf app_exe *.o
