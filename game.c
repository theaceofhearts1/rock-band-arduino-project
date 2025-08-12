#include <stdbool.h>
#include "game.h" 
#include "neopixel.h"
#include "ws2812b.h"

static volatile uint8_t * const PIXELS_DDR  = &DDRD;
static volatile uint8_t * const PIXELS_PORT = &PORTD;
static const uint8_t            PIXELS_BIT  = PD0;

// We create a union for display and ws2812b buffers to avoid violating
// the strict aliasing rule which would introduce undefined behavior.
static union {
    display_buffer_t display;
    ws2812b_buffer_t ws2812b[PIXELS];
} buffer;

static_assert(
    sizeof(buffer.display) == sizeof(buffer.ws2812b),
    "display and ws2812b buffers must match in size");

//---------------------------------------------------------------------------------

#define SIZE 10
#define DOT_COUNT 4

int row_pos[DOT_COUNT];            // Current row of each dot
int start_delays[DOT_COUNT] = {0, 1, 2, 3};  // Frames before each dot starts

const uint8_t DOT_COLOR = 255; // yellow (combining red + green)

while (1) {
    // 1. Clear the display buffer
    for (int r = 0; r < SIZE; r++)
        for (int c = 0; c < SIZE; c++)
            for (int ch = 0; ch < WS2812B_COLOR_TOTAL; ch++)
                buffer.display[r][c][ch] = 0;

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
                row_pos[d] = 0;
                start_delays[d] = DOT_COUNT * 5;  // reset delay for loop
            }
        }
    }
}

    // 3. Send display buffer to LEDs
    *PIXELS_DDR |= (1 << PIXELS_BIT);
    *PIXELS_PORT &= ~(1 << PIXELS_BIT);
    _delay_us(50);
    ws2812b_tx(PIXELS_PORT, PIXELS_BIT, buffer.ws2812b, SIZE * SIZE);

    // 4. Frame delay controls speed
    _delay_ms(100);

void update_score(void){
	
}

void level_start(){

}

void level_end(){

}

void target_waterfall(){

}

void target_die(){

}

void target_collect(){

}

void target_spawn(void){
for (uint8_t i = 0; i <= 3; i++){
	target_positions[i] = (1 + (i*2));
	}
}

void target_functionality() {
	switch (target_state){
		case is_falling:
		break;
		case is_spawned:
		break;
		case is_collected:
		break;
		case is_killed: 
		break;
	}
}