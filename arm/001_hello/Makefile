#PREFIX=aarch64-linux-android-
PREFIX=arm-linux-gnueabihf-
CC=gcc
CFLAGS=-I.

DEPS=app.o

%.o:%.c
	$(PREFIX)$(CC) -c $< -o $@ $(CFLAGS) -g

app_exe:$(DEPS)
	$(PREFIX)$(CC) -o $@ $^ $(CFLAGS)
	cp app_exe /var/lib/tftpboot

clean:
	rm -rf app_exe *.o
