CC_PREFIX:=arm-none-eabi-

OBJS:=app.o syscalls.o

TARGET:=appExe

%.o:%.c
	$(CC_PREFIX)gcc -c -std=c11 -pedantic -o $@ $<

$(TARGET):$(OBJS)
	$(CC_PREFIX)gcc $^ -Xlinker -Map=$(TARGET).map -std=c11 -pedantic -o $@

clean:
	rm -rf *.o $(TARGET) $(TARGET).map

dump:
	$(CC_PREFIX)objdump -x $(TARGET)

size:
	size $(TARGET)
	size -A $(TARGET)
	size -G $(TARGET)

nm:
	$(CC_PREFIX)nm $(TARGET)

strings:
	$(CC_PREFIX)strings $(TARGET)

dis:
	$(CC_PREFIX)objdump -d $(TARGET)

