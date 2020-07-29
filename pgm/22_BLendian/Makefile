CC=arm-linux-gnueabihf-gcc
#CC=gcc
CFLAGS=-I.

DEPS=app.o

%.o:%.c
	$(CC) -c $< -o $@ $(CFLAGS) -g

app_exe:$(DEPS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf app_exe *.o
