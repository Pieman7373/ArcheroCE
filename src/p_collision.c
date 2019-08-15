#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fileioc.h>
#include <graphx.h>
#include <keypadc.h>

#include "projectiles.h"
#include "main.h"
#include "gfx/tiles_gfx.h"
#include "gfx/archero_gfx.h"
#include "mainloop.h"
#include "structs.h"

extern int goleft;
extern int goup;
extern int goright;
extern int godown;
extern int tmp_pxl_x_offset;
extern int tmp_pxl_y_offset;
extern int p_pxl_x;
extern int p_pxl_y;
extern int walkstep;
extern gfx_tilemap_t tilemap;

void pcollisiondown(){
	if ((gfx_GetTile(&tilemap,(tmp_pxl_x_offset + ((p_pxl_x) - TILEMAP_POS_X)),(tmp_pxl_y_offset + ((p_pxl_y + 16) - TILEMAP_POS_Y)) + walkstep)) < 8){
		godown = 1;
	}
	else if ((gfx_GetTile(&tilemap,(tmp_pxl_x_offset + ((p_pxl_x + 8) - TILEMAP_POS_X)),(tmp_pxl_y_offset + ((p_pxl_y + 16) - TILEMAP_POS_Y)) + walkstep)) < 8){
		godown = 1;
	}
}
void pcollisionleft(){
	goleft = 1;
}
void pcollisionup(){
	goup = 1;
}
void pcollisionright(){
	goright = 1;
}