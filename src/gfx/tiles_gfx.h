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
#define tileset_tiles_num 2
extern uint8_t *tileset_tiles_data[2];
#define tileset_tiles ((gfx_sprite_t**)tileset_tiles_data)
#define sizeof_tiles_gfx_pal 512
extern uint16_t tiles_gfx_pal[256];

#endif
