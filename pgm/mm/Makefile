CC=gcc
CFLAGS=-I.
MM_OBJ=mm.o
STK_OBJ=stk_smash.o

vinai: mm_exe stk_exe

%.o: %.c
	$(CC) -g -c -o $@ $< $(CFLAGS)

mm_exe: $(MM_OBJ)
	$(CC) -g -o $@ $^ $(CFLAGS)

stk_exe: $(STK_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf *.o mm_exe stk_exe
