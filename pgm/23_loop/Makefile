#CROSS=arm-linux-gnueabihf-
CC=gcc
CFLAGS=-I.

DEPS=app.o

%.o:%.c
	$(CROSS)$(CC) -c $< -o $@ $(CFLAGS) -g

app_exe:$(DEPS)
	$(CROSS)$(CC) -o $@ $^ $(CFLAGS)
	cp app_exe /var/lib/tftpboot

clean:
	rm -rf app_exe *.o
