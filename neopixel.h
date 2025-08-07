#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <stddef.h>
#include <avr/pgmspace.h>

void setup_pins(void);

void shift_down(uint8_t target_number);

void light_display(void);

const uint8_t display_length;