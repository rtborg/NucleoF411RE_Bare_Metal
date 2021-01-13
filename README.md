# Nucleo F411RE Bare Metal Development setup

The program does not make use of HAL and CMSIS drivers, or an IDE. 

## Files
* `main.c` - contains MCU code, a round-robin scheduler
* `led.c` - contains code for initializing 4 LEDs
* `stm32_startup.c` - contains vector table and reset handler 
* `stm32f411re_linkerscipt.ld` - the linker script describes how data is written on the mcu
* `syscalls.c` - the program uses standard library
* `Makefile` - for automating of compilation

## Dependencies
The compilation and flashing work with: 

`arm-none-eabi-gcc (GNU Arm Embedded Toolchain 10-2020-q4-major) 10.2.1 20201103 (release)`

`xPack OpenOCD, x86_64 Open On-Chip Debugger 0.10.0+dev`

## How to use
Download the code, go to the folder and run

`make clean` 

`make` - that will generate an `final.elf` file which you can flash

`make semi` - that will generate a `final_sh.elf` file which makes usage of standard library

`make load` - that will start OpenOCD