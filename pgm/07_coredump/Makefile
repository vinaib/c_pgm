CC=gcc
CFLAGS=-I.
DEBUG=-g
FLAGS=-Wall

OBJ=app.o

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) $(DEBUG) $(FLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(DEBUG) $(FLAGS)

clean:
	rm -rf exe *.o
