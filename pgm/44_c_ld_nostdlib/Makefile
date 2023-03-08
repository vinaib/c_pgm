# arch

CC_PREFIX:=arm-none-eabi-
CC:=gcc
LD:=ld
NM:=nm
STRINGS:=strings
OBJDUMP:=objdump

# linker follows this order
OBJS:=app.o syscalls.o roData.o bssData.o

LDTARGET:= ldAppExe

%.o:%.c
	$(CC_PREFIX)$(CC) -c -g -std=c11 -nostdlib -o $@ $<

$(LDTARGET):$(OBJS)
	$(CC_PREFIX)$(LD) $^ -nostdlib -T app.ld -Map=$(LDTARGET).map -o $@

clean:
	rm -rf *.o $(LDTARGET) $(LDTARGET).map

section:$(OBJS)
	$(CC_PREFIX)$(OBJDUMP) -h $^
	$(CC_PREFIX)$(OBJDUMP) -h $(LDTARGET)
dump:
	$(CC_PREFIX)$(OBJDUMP) -x $(LDTARGET)

size:
	size $(LDTARGET)
	size -A $(LDTARGET)
	size -G $(LDTARGET)

nm:
	$(CC_PREFIX)$(NM) $(LDTARGET)

strings:
	$(CC_PREFIX)$(STRINGS) $(LDTARGET)

dis:
	$(CC_PREFIX)$(OBJDUMP) -d $(LDTARGET)

