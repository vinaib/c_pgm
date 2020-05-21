CC=gcc

OBJ=eg.o

%.o: %.c
	$(CC) -c $< -o $@

app: $(OBJ)
	$(CC) -Wall -Wextra -Werror -o $@ $^

clean:
	rm -rf *.o app
