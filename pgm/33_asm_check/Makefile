PREFIX=arm-linux-gnueabihf-
CC=gcc
AS=as
CFLAGS=-I.

GENERATE_ASM=app.s
DEPS=app.o

%.s:%.c
	$(PREFIX)$(CC) -marm -S $< -o $@ $(CFLAGS)

%.o:%.c
	$(CC) -g -c $< -o $@ $(CFLAGS)

app.s:

app_exe:$(DEPS)
	$(CC) -g -o $@ $^ $(CFLAGS)

clean:
	rm -rf app_exe *.o *.s
