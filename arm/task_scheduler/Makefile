CC=arm-none-eabi-gcc
LD=arm-none-eabi-ld
MACH=cortex-m4
CFLAGS=-mcpu=$(MACH) -mthumb -std=gnu11 -O0 -Wall -I.
LDFLAGS= -nostdlib -T stm32.ld -Map=app.map

OBJS=main.o stm32_startup.o
	
%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@
	
app_elf: $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	del *.o app_elf app.map
