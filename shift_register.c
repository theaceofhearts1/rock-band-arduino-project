#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <stddef.h>
#include <avr/pgmspace.h>

   	#define DS_PIN PD0
    #define SHCP_PIN PD1
    #define STCP_PIN PD2
    #define DATA_PORT PORTD
    #define DATA_DDR DDRD

void HC595_Init(void) {
	DATA_DDR |= (1 << DS_PIN) | (1 << SHCP_PIN) | (1 << STCP_PIN);
    }

	void HC595_Write(uint8_t data) {
        DATA_PORT &= ~(1 << STCP_PIN); // Latch pin LOW

        for (int i = 0; i < 8; i++) {
            DATA_PORT &= ~(1 << SHCP_PIN); // Clock pin LOW
            if (data & 0x80) { // Check MSB
                DATA_PORT |= (1 << DS_PIN); // Data pin HIGH
            } else {
                DATA_PORT &= ~(1 << DS_PIN); // Data pin LOW
            }
            DATA_PORT |= (1 << SHCP_PIN); // Clock pin HIGH (pulse)
            data <<= 1; // Shift to next bit
        }
        DATA_PORT |= (1 << STCP_PIN); // Latch pin HIGH
    }

	   const uint8_t seven_seg_digits[] = {
        0xC0, // 0
        0xF9, // 1
        0xA4, // 2
        0xB0, // 3
        0x99, // 4
        0x92, // 5
        0x82, // 6
        0xF8, // 7
        0x80, // 8
        0x90  // 9
    };

    void displayDigit(uint8_t digit) {
        if (digit >= 0 && digit <= 9) {
            HC595_Write(seven_seg_digits[digit]);
        }
    }