// convpng v7.1
// this file contains all the graphics sources for easy inclusion in a project
#ifndef __tiles_gfx__
#define __tiles_gfx__
#include <stdint.h>

#define tiles_gfx_transparent_color_index 0

extern uint8_t tileset_tile_0_data[];
#define tileset_tile_0 ((gfx_sprite_t*)tileset_tile_0_data)
extern uint8_t tileset_tile_1_data[];
#define tileset_tile_1 ((gfx_sprite_t*)tileset_tile_1_data)
extern uint8_t tileset_tile_2_data[];
#define tileset_tile_2 ((gfx_sprite_t*)tileset_tile_2_data)
extern uint8_t tileset_tile_3_data[];
#define tileset_tile_3 ((gfx_sprite_t*)tileset_tile_3_data)
extern uint8_t tileset_tile_4_data[];
#define tileset_tile_4 ((gfx_sprite_t*)tileset_tile_4_data)
extern uint8_t tileset_tile_5_data[];
#define tileset_tile_5 ((gfx_sprite_t*)tileset_tile_5_data)
extern uint8_t tileset_tile_6_data[];
#define tileset_tile_6 ((gfx_sprite_t*)tileset_tile_6_data)
extern uint8_t tileset_tile_7_data[];
#define tileset_tile_7 ((gfx_sprite_t*)tileset_tile_7_data)
extern uint8_t tileset_tile_8_data[];
#define tileset_tile_8 ((gfx_sprite_t*)tileset_tile_8_data)
extern uint8_t tileset_tile_9_data[];
#define tileset_tile_9 ((gfx_sprite_t*)tileset_tile_9_data)
extern uint8_t tileset_tile_10_data[];
#define tileset_tile_10 ((gfx_sprite_t*)tileset_tile_10_data)
extern uint8_t tileset_tile_11_data[];
#define tileset_tile_11 ((gfx_sprite_t*)tileset_tile_11_data)
extern uint8_t tileset_tile_12_data[];
#define tileset_tile_12 ((gfx_sprite_t*)tileset_tile_12_data)
extern uint8_t tileset_tile_13_data[];
#define tileset_tile_13 ((gfx_sprite_t*)tileset_tile_13_data)
extern uint8_t tileset_tile_14_data[];
#define tileset_tile_14 ((gfx_sprite_t*)tileset_tile_14_data)
extern uint8_t tileset_tile_15_data[];
#define tileset_tile_15 ((gfx_sprite_t*)tileset_tile_15_data)
#define tileset_tiles_num 16
extern uint8_t *tileset_tiles_data[16];
#define tileset_tiles ((gfx_sprite_t**)tileset_tiles_data)
#define sizeof_tiles_gfx_pal 512
extern uint16_t tiles_gfx_pal[256];

#endif
