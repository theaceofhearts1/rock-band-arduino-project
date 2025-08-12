#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <stddef.h>
#include <avr/pgmspace.h>

#define ROWS    10
#define COLUMNS 10
#define PIXELS  (ROWS * COLUMNS)

typedef uint8_t display_buffer_t[ROWS][COLUMNS][WS2812B_COLOR_TOTAL];

#define TARGET_SPEED 10

uint8_t target_positions[4];

void target_spawn();

uint16_t score;

uint16_t target_amount;

typedef enum{
	is_falling,
	is_spawned,
	is_collected,
	is_killed,
} target_status_t;

target_status_t target_state;

