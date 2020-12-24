FW_NAME = pc9in
#STM32F4_LIB_DIR = ../STM32F4_DISC_LIB
CC=arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
CFLAGS = -g -Wall -O3
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16 
CFLAGS += -I ../inc/ST/STM32F4xx/
CFLAGS += -I ../inc/CMSIS/
#CFLAGS += -T $(STM32F4_LIB_DIR)/stm32_flash.ld
CFLAGS += --specs=nosys.specs
OBJS=main.o 
SRCS = main.c
#SRCS += $(STM32F4_LIB_DIR)/system_stm32f4xx.c
#SRCS += $(STM32F4_LIB_DIR)/Libraries/CMSIS/ST/STM32F4xx/Source/Templates/TrueSTUDIO/startup_stm32f4xx.s

all: $(FW_NAME)

clean:
		rm -f *.o $(FW_NAME).elf $(FW_NAME).hex $(FW_NAME).bin

$(FW_NAME): $(OBJS)
		$(CC) $(CFLAGS) $^ -o $(FW_NAME).elf
		$(OBJCOPY) -O ihex $(FW_NAME).elf $(FW_NAME).hex
		$(OBJCOPY) -O binary $(FW_NAME).elf $(FW_NAME).bin
		cp $(FW_NAME).elf /mnt/c/Users/swkim/Documents/
		cp $(FW_NAME).bin /mnt/c/Users/swkim/Documents/
		cp $(FW_NAME).hex /mnt/c/Users/swkim/Documents/
