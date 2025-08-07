set arch avr
file main.elf
set serial baud 115200
target remote /dev/ttyACM1
layout src
focus cmd
