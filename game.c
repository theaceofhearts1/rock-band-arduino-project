#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "game.h" 
#include "neopixel.h"
#include "ws2812b.h"
#include <assert.h>
#include <stdint.h>

static volatile uint8_t * const PIXELS_DDR  = &DDRD;
static volatile uint8_t * const PIXELS_PORT = &PORTD;
static const uint8_t            PIXELS_BIT  = PD0;

// We create a union for display and ws2812b buffers to avoid violating
// the strict aliasing rule which would introduce undefined behavior.
static union {
    display_buffer_t display;
    ws2812b_buffer_t ws2812b[PIXELS];
} buffer;
//---------------------------------------------------------------------------------

static_assert(
    sizeof(buffer.display) == sizeof(buffer.ws2812b),
    "display and ws2812b buffers must match in size");

#define SIZE 10
#define DOT_COUNT 4

int row_pos[DOT_COUNT];            // Current row of each dot
int start_delays[DOT_COUNT];  // Frames before each dot starts

bool ready_to_be_collected[DOT_COUNT];

const uint8_t DOT_COLOR = 255; // yellow (combining red + green)

uint32_t the_ultimate_random_number;

uint8_t random_num_gen(uint8_t random_int){
	srand(4);
	for (int i =  0; i < rand(); i++){
srand(random_int);
the_ultimate_random_number = the_ultimate_random_number + rand();
}

return (the_ultimate_random_number % 11);
} 

void delay_setter(int Current_target){
	start_delays[Current_target] = random_num_gen(score);
}

void level_start(){
	DDRC = 0x00;
	for (int i = 0; i <= (DOT_COUNT - 1); i++) {
		delay_setter(i);
		}
//start game run targte_waterfall and clear neo_pixel buffer
    for (int r = 0; r < SIZE; r++)
        for (int c = 0; c < SIZE; c++)
            for (int ch = 0; ch < WS2812B_COLOR_TOTAL; ch++)
                buffer.display[r][c][ch] = 0;

}



void level_end(){
//WIP
}

bool button_pressed(uint8_t button_number){
	if ((PINC & (1 << button_number)) == 1) {
		return 1;
	} else {
		return 0;
	}
}

void target_collect(){
	for (int i = 2; i <= 5; i++){
	if (button_pressed(i) == 1) {
		if (ready_to_be_collected[i - 1] == 1) {
			if (golden == 1){
				score = score + 2;
			} else {
					score++;
				}
			}
		} else {
			score--;
			}
		}
	}


void run_game(){
    // 2. Update dots
    for (int d = 0; d < DOT_COUNT; d++) {
        if (start_delays[d] > 0) {
            start_delays[d]--;
        } else {
            if (row_pos[d] >= 0) {
                int r = row_pos[d];
                int c = SIZE / 2;
                buffer.display[r][c][WS2812B_COLOR_RED]   = DOT_COLOR;
                buffer.display[r][c][WS2812B_COLOR_GREEN] = DOT_COLOR;
            }
            row_pos[d]++;
            if (row_pos[d] >= SIZE) {
				if (row_pos[d] == SIZE){
				ready_to_be_collected[d] = 1;
				row_pos[d] = 0;
                delay_setter(d);  // reset delay for loop
				} else {
				ready_to_be_collected[d] = 0;
                row_pos[d] = 0;
                delay_setter(d);  // reset delay for loop
				}
            } 
			else {
				ready_to_be_collected[d] = 0;
			}
        }
    }
}

void display_pixel_design(){
    *PIXELS_DDR |= (1 << PIXELS_BIT);
    *PIXELS_PORT &= ~(1 << PIXELS_BIT);
    _delay_us(50);
    ws2812b_tx(PIXELS_PORT, PIXELS_BIT, buffer.ws2812b, SIZE * SIZE);
	_delay_ms(100);
}
