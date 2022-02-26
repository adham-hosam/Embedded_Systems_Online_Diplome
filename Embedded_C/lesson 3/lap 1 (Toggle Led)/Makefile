#copyright: ADHAM_HOSAM	
CC=arm-none-eabi-
CFLAGS =  -mthumb -mcpu=cortex-m3
INCS= -I .
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
Project_name = learn-in-depth-cortex-m3
all:$(Project_name).bin
	@echo "========Build is done========"
	
		 
%.o: %.c
	$(CC)gcc.exe  -c $(CFLAGS) $(INCS) $< -o $@
		
$(Project_name).elf:$(OBJ) $(AsOBJ)
	$(CC)ld.exe  -T linker_script.ld $(OBJ) $(AsOBJ) -o $@ -Map=MAP_file.map
	@echo "done"
	
$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $<  $@

clean_all :
	rm *.o *.bin *.elf

clean :
	rm *.bin *.elf
	