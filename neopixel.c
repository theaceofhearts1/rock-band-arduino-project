#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <stddef.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "game.h"
#include "neopixel.h"

const uint8_t display_length = 1;

uint8_t pins_LMAO[6] = {
	PB0,
	PB1,
	PB2,
	PB3,
	PB4,
	PB5,
};

//--temporary code----
void setup_pins(void){
DDRB = 0xFF;
}

//-----PSEUDO CODE------

void pixel_write(){

}

uint8_t pixel_read(){
return 0;
}


void light_display(void){
	for (uint8_t i = 0; i < 6; i++) {
		if (i == target_positions[0]) {
			PORTB |= (1 << i);
		} else {
			PORTB |= (0 << i);
		}
		} _delay_ms(100);
		target_positions[0] = (target_positions[0] +  display_length);
	}
