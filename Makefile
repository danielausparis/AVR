##############################################################################
#
#     generic Makefile for avr-gcc and friends
#
#              Daniel Ranc 2013
#
#              designed for GNU make
#
#
##############################################################################


##############################################################################
# project-specific settings, configure for each project
##############################################################################

# project name
PROJECT = blink-trans

# libraries
INCLUDES = -I../../include
LIBRARY_PATH =
LIBS =

# ADC
INCLUDES += -I../../libs/ADC
LIBRARY_PATH += -L../../libs/ADC
LIBS += -lADC

# UART
INCLUDES += -I../../libs/UART
LIBRARY_PATH += -L../../libs/UART
LIBS += -lUART

# fleury I2C
INCLUDES += -I../../libs/fleury_i2cmaster
LIBS += -ltwi_master
LIBRARY_PATH += -L../../libs/fleury_i2cmaster


# target AVR processor in lingua avr-gcc:
PROC = atmega328p
# target AVR processor in lingua avrdude:
AVRDUDE_PROC = m328p

# clock
F_CPU = 16000000UL

# Fuse values (danger :-/ )
LFUSE = 0xce
HFUSE = 0xdf


##############################################################################
# installation-dependant settings, configure once for your host
##############################################################################

# programmer type
#PROGRAMMER = usbasp
PROGRAMMER = arduino
# serial or parallel port to which your hardware programmer is attached
AVRDUDE_PORT = /dev/ttyUSB0

# permission problems?
# => create /etc/udev/rules.d/10-usbprog.rules with:
# SUBSYSTEM=="usb", SYSFS{idVendor}=="1781", SYSFS{idProduct}=="0c9f", GROUP="adm", MODE="0666"
# (replace ids by your ids)
# and restart udev.


##############################################################################
# general settings & rules - DO NOT MODIFY
##############################################################################


# source files:
SOURCES = $(wildcard *.c)
# headers:
HEADERS = $(wildcard *.h)
# list of object files:
OBJS = $(SOURCES:.c=.o)

# target "burnable" file name:
PROJECT_HEX = $(PROJECT).hex

# compiler used to compile source files.
CC = avr-gcc
# asssembler used to produce object files.
AS = avr-as
# the linker.
LD = avr-ld
# the loader
LOADER = avrdude

# Compiler flags go here.
CFLAGS = -mmcu=$(PROC) -Wall -g -Os -D CLOCK=$(F_CPU) -D F_CPU=$(F_CPU) $(INCLUDES)
# Assembler flags:
ASFLAGS =
# Linker flags go here.
LDFLAGS = -Wl,-Map,$(PROJECT).map $(LIBRARY_PATH)
# Avrdude flags
LOADERFLAGS = -c $(PROGRAMMER) -P $(AVRDUDE_PORT) -p $(AVRDUDE_PROC)
#UPLOAD_LOADERFLAGS = -DV -c arduino -P $(AVRDUDE_PORT) -p $(PROC) -u -b 57600
UPLOAD_LOADERFLAGS = -p $(AVRDUDE_PROC) -c arduino -b 57600 -P $(AVRDUDE_PORT)

# top-level rule
all: $(PROJECT_HEX)

# rule for compiling any C source file.
# This one breaks some stuff with patterns. ?
# .c.o: $(HEADERS) $(SOURCES)
# 	@printf "Compiling $<... "
# 	$(CC) $(CFLAGS) -c $< -o $@

%.o : %.c
	@printf "Compiling $<... "
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@


# rule for linking the objects and produce .lst file
$(PROJECT).elf: $(OBJS)
	@printf "Linking $(PROJECT)... "
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(PROJECT).elf $(OBJS) $(LIBS)
	@printf "Producing $(PROJECT).lst... "
	@avr-objdump -m avr -S $(PROJECT).elf > $(PROJECT).lst
	@echo "done."

# rule generating hex file:
$(PROJECT_HEX): $(PROJECT).elf
	@printf "Generating $(PROJECT).hex... "
	@avr-objcopy -R .eeprom -O ihex $(PROJECT).elf  $(PROJECT_HEX)
	@echo "done."

# make clean & tidy
clean:
	$(RM) *.asm *.o *.lst *.hex *.map *.out *.elf

burn: $(PROJECT_HEX)
	$(LOADER) $(LOADERFLAGS) -U flash:w:$(PROJECT_HEX)

#upload: $(PROJECT_HEX)
#	$(LOADER) $(UPLOAD_LOADERFLAGS) -U flash:w:$(PROJECT_HEX):i

dump:
	@printf "Dumping device to file dump.hex..."
	$(LOADER) $(LOADERFLAGS) -i 5 -U flash:r:dump.hex:i
	@echo "done."

rfuse:
	@printf "Reading fuses to files high.twt and low.txt..."
	$(LOADER) $(LOADERFLAGS) -U lfuse:r:low.txt:b -U hfuse:r:high.txt:b > /dev/null 2>&1
	@echo "done."

#wfuse:
#	@printf "Writing fuses..."
#	$(LOADER) $(LOADERFLAGS) -U lfuse:w:$(LFUSE):m -U hfuse:w:$(HFUSE):m  > /dev/null 2>&1
#	@echo "done."
