CC=gcc
CFLAGS=-I.
LD=ld

DEPS=defs.h
OBJS=app.o

exe: app_exe

%.o: %.c $(DEPS)
	$(CC) -o $@ -c $< $(CFLAGS)

app_exe: $(OBJS)
	$(CC) -o $@ $^
	wc -c $@

app1_exe: app_1.c
	$(CC) -v -o $@ $<
	wc -c $@

app2_exe: app_2.c
	$(CC) -v -o $@ $< -nostdlib
	wc -c $@

clean:
	rm -rf app_exe app1_exe app2_exe *.o
