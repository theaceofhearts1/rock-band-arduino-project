#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <stddef.h>
#include <avr/pgmspace.h>
#include "game.h"
#include "neopixel.h"

int main (void) {
	target_spawn();
	setup_pins();
	light_display();
	return 0;
}

//The fucntion above wont work i can get it to light up the LED's