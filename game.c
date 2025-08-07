#include <stdbool.h>
#include "game.h" 
#include "neopixel.h"

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