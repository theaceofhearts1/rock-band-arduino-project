CC      = avr-gcc
CFLAGS += \
    -DF_CPU=16000000ULL \
    -Og \
    -Wall \
    -Wextra \
	-Werror \
    -g \
    -mmcu=atmega328p \
    -std=gnu11 \

.PHONY: all
all: main.elf

.PHONY: clean
clean:
	@rm -rvf *.d *.elf *.o

main.elf: main.o game.o neopixel.o ws2812b.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.S
	$(CC) $(CFLAGS) -MM -MF $*.d $<
	$(CC) $(CFLAGS) -c $<

%.o: %.c
	$(CC) $(CFLAGS) -MM -MF $*.d $<
	$(CC) $(CFLAGS) -c $<

-include $(wildcard *.d)