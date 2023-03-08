CC_PREFIX:=arm-none-eabi-
CC:=gcc
LD:=ld
NM:=nm
STRINGS:=strings
OBJDUMP:=objdump

# linker follows this order
OBJS:=app.o syscalls.o roData.o bssData.o

TARGET:=appExe

%.o:%.c
	$(CC_PREFIX)$(CC) -c -std=c11 -nostdlib -o $@ $<

$(TARGET):$(OBJS)
	$(CC_PREFIX)$(CC) $^ -std=c11 -nostdlib -Xlinker -Map=$(TARGET).map -o $@

clean:
	rm -rf *.o $(TARGET) $(TARGET).map

section:$(OBJS)
	$(CC_PREFIX)$(OBJDUMP) -h $^
	$(CC_PREFIX)$(OBJDUMP) -h $(TARGET)
dump:
	$(CC_PREFIX)$(OBJDUMP) -x $(TARGET)

size:
	size $(TARGET)
	size -A $(TARGET)
	size -G $(TARGET)

nm:
	$(CC_PREFIX)$(NM) $(TARGET)

strings:
	$(CC_PREFIX)$(STRINGS) $(TARGET)

dis:
	$(CC_PREFIX)$(OBJDUMP) -d $(TARGET)

