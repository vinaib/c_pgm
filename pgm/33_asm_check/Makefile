PREFIX=arm-linux-gnueabihf-
CC=gcc
AS=as
CFLAGS=-I.

OBJS := app.o asm_routine.o

#Generate asm file
%.s:%.c
	$(PREFIX)$(CC) -marm -S $< -o $@ $(CFLAGS)

%.o:%.s
	$(PREFIX)$(AS) -g $< -o $@

%.o:%.c
	$(PREFIX)$(CC) -g -c $< -o $@ $(CFLAGS)

app_exe:$(OBJS)
	$(PREFIX)$(CC) -g -o $@ $^ $(CFLAGS)
	cp $@ /var/lib/tftpboot

clean:
	rm -rf app_exe *.o
