#copyright: ADHAM_HOSAM	
CC=arm-none-eabi-
CFLAGS =-g  -mcpu=arm926ej-s
INCS= -I .
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
Project_name = learn-in-depth
all:learn-in-depth.bin
	@echo "========Build is done========"
	
%.o: %.s
	$(CC)as.exe  $(CFLAGS) $< -o $@
		 
%.o: %.c
	$(CC)gcc.exe  -c $(INCS) $(CFLAGS) $< -o $@
		
$(Project_name).elf:$(OBJ) $(AsOBJ)
	$(CC)ld.exe  -T linker_script.ld $(OBJ) $(AsOBJ) -o $@ -Map=MAP_file.map
	
$(Project_name).bin: learn-in-depth.elf
	$(CC)objcopy.exe -O binary $<  $@

clean_all :
	rm *.o *.bin *.elf

clean :
	rm *.bin *.elf
	