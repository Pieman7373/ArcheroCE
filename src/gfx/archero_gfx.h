// convpng v7.1
// this file contains all the graphics sources for easy inclusion in a project
#ifndef __archero_gfx__
#define __archero_gfx__
#include <stdint.h>

#define archero_gfx_transparent_color_index 0

#define stickman_width 8
#define stickman_height 16
#define stickman_size 130
extern uint8_t stickman_data[130];
#define stickman ((gfx_sprite_t*)stickman_data)
#define test_bullet_width 16
#define test_bullet_height 16
#define test_bullet_size 258
extern uint8_t test_bullet_data[258];
#define test_bullet ((gfx_sprite_t*)test_bullet_data)
#define sizeof_archero_gfx_pal 512
extern uint16_t archero_gfx_pal[256];

#endif
