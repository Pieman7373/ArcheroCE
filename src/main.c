/*
 *--------------------------------------
 * Program Name:ArcheroCE
 * Author:Pieman7373
 * License:
 * Description:
 *--------------------------------------
*/

/* Keep these headers */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

/* Standard headers (recommended) */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fileioc.h>
#include <graphx.h>
#include <keypadc.h>

#include "main.h"
#include "gfx/tiles_gfx.h"
#include "mainloop.h"

/* Put your function prototypes here */

/* Put all your globals here */
int transcolor = (0xF8);

/* tilemap stuff */
#define TILEMAP_POS_X           0
#define TILEMAP_POS_Y           79

extern uint8_t tilemap_map[];
gfx_tilemap_t tilemap;

void main(void) {
	kb_key_t key;
	
	/* Initialize the tilemap structure */
	tilemap.map         = tilemap_map;
    tilemap.tiles       = tileset_tiles;
    tilemap.type_width  = gfx_tile_16_pixel;
    tilemap.type_height = gfx_tile_16_pixel;
    tilemap.tile_height = TILEMAP_TILE_SIZE;
    tilemap.tile_width  = TILEMAP_TILE_SIZE;
    tilemap.draw_height = TILEMAP_DRAW_HEIGHT;
    tilemap.draw_width  = TILEMAP_DRAW_WIDTH;
    tilemap.height      = TILEMAP_HEIGHT;
    tilemap.width       = TILEMAP_WIDTH;
    tilemap.y_loc       = TILEMAP_POS_X;
    tilemap.x_loc       = TILEMAP_POS_Y;

	
	
	gfx_Begin();
	gfx_SetPalette(tiles_gfx_pal, sizeof_tiles_gfx_pal, 0);
	gfx_SetTransparentColor(transcolor);
	
		mainloop();
	
	gfx_End();
}

/* Put other functions here */
