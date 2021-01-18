TARGET = libblake3.so
#STM32F4_LIB_DIR = ../STM32F4_DISC_LIB
CC=arm-none-eabi-gcc
CFLAGS = -g -Wall -O3 -shared
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16 
#CFLAGS += -T $(STM32F4_LIB_DIR)/stm32_flash.ld
CFLAGS += --specs=nosys.specs
OBJS = libblake3.o 
SRCS = blake3.c blake3_dispatch.c blake3_portable.c
#SRCS += $(STM32F4_LIB_DIR)/Libraries/CMSIS/ST/STM32F4xx/Source/Templates/TrueSTUDIO/startup_stm32f4xx.s

all:
		$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
		rm -f *.o $(TARGET)
