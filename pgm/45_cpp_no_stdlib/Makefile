# arch

CC_PREFIX:=arm-none-eabi-
CPP:=g++
LD:=ld
NM:=nm
STRINGS:=strings
OBJDUMP:=objdump

# linker follows this order
OBJS:=app.o syscall.o

LDTARGET:= ldAppExe

%.o:%.cpp
	$(CC_PREFIX)$(CPP) -c $< -std=c++17 -nostdlib -fno-exceptions -o $@

$(LDTARGET):$(OBJS)
	$(CC_PREFIX)$(LD) $^ -nostdlib -T app.ld -Map=$(LDTARGET).map -o $@

clean:
	rm -rf *.o $(LDTARGET) $(LDTARGET).map

section:$(OBJS)
	$(CC_PREFIX)$(OBJDUMP) -h $^
	$(CC_PREFIX)$(OBJDUMP) -h $(LDTARGET)

dump:$(OBJS)
	$(CC_PREFIX)$(OBJDUMP) -x $^
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

