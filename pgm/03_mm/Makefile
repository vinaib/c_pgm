CC=gcc
#CC=arm-linux-gnueabihf-gcc
CFLAGS=-I.
MM_OBJ=mm.o
STK_OBJ=stk_smash.o
CMD_LINE_OBJ=cmd_line.o

vinai: mm_exe stk_exe cmd_exe

%.o: %.c
	$(CC) -g -c -o $@ $< $(CFLAGS)

mm_exe: $(MM_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

stk_exe: $(STK_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

cmd_exe: $(CMD_LINE_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf *.o *_exe
