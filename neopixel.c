#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <stddef.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

//--temporary code----
void setup_pins(void){
	for (uint8_t i = 1; i < 6; i++) {
	DDRB =| (1 << (7+i));
	}
}



//-----PSEUDO CODE------

void pixel_write(){

}

uint8_t pixel_read(){
return 0;
}

void shift_down(uint8_t target_number){
target_positions[target_number-1] = (target_positions[target_number-1] +  display_length);
light_display();
_delay_ms(100);
}

void light_display(void){
	for (uint8_t i = 0; i < 6; i++) {
		if (i = target_positions[1]) {
			PORTB =| (1 << i);
		} Else {
			PORTB =| (0 << i);
		}
	}
}