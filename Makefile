# Variables
CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -std=gnu11 -O0 -Wall
LINKERFLAGS= -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=nano.specs -T stm32f411re_linkerscipt.ld -Wl,-Map=final.map
# Linker flags for enabling semihosting:
LINKERFLAGS_SH= -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=rdimon.specs -T stm32f411re_linkerscipt.ld -Wl,-Map=final.map


# Targets 

all:main.o led.o stm32_startup.o syscalls.o final.elf
semi:main.o led.o stm32_startup.o syscalls.o final_sh.elf

main.o:main.c
	$(CC) $(CFLAGS) $^ -o $@
	
led.o:led.c
	$(CC) $(CFLAGS) $^ -o $@
	
stm32_startup.o:stm32_startup.c
	$(CC) $(CFLAGS) $^ -o $@

syscalls.o:syscalls.c
	$(CC) $(CFLAGS) $^ -o $@

final.elf:main.o led.o stm32_startup.o syscalls.o
	$(CC) $(LINKERFLAGS) $^ -o $@

final_sh.elf:main.o led.o stm32_startup.o
	$(CC) $(LINKERFLAGS_SH) $^ -o $@	

clean: 
	rm -rf *.o *.el

# OpenOCD command
load:
	openocd -f board/st_nucleo_f4.cfg 