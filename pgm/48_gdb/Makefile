CC=gcc

OBJ=first.o
REC_OBJ=first.o

ENABLE_DEBUG=-g

%.o: %.c
	$(CC) -c $(ENABLE_DEBUG) $< -o $@

app: $(OBJ)
	$(CC) -Wall -Wextra -Werror -o $@ $^

clean:
	rm -rf *.o app
