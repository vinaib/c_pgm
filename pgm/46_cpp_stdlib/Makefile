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
	$(CC_PREFIX)$(CPP) -c -std=c++17 -o $@ $<

$(LDTARGET):$(OBJS)
	$(CC_PREFIX)$(CPP) $^ -Xlinker -Map=$(LDTARGET).map -o $@

clean:
	rm -rf *.o $(LDTARGET) $(LDTARGET).map

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

