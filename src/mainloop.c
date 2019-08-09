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

#include "main.h"
#include "gfx/tiles_gfx.h"
#include "gfx/archero_gfx.h"
#include "mainloop.h"
#include "structs.h"
//#include "projectiles.h"

//tilemap pixel offsets
int tmp_pxl_x_offset = 0;
int tmp_pxl_y_offset = 0;

//player screen coordinates in pixels
int p_pxl_x = 100;
int p_pxl_y = 100;
int walking = 0;

extern gfx_tilemap_t tilemap;
extern bullets_t bullets;

void mainloop() {
	do {
		updatebullets();
			gfx_SetDrawBuffer();
				drawmap();
				drawplayer();
				renderbullets();
			gfx_SwapDraw();
		keycheck();
	} while (!(kb_Data[6] & kb_Clear));
}

void drawmap(){
	gfx_FillScreen(0x00);
	gfx_Tilemap(&tilemap,tmp_pxl_x_offset,tmp_pxl_y_offset);
		gfx_SetTextFGColor(0xfe);
		gfx_SetTextXY(0,0);
		gfx_PrintInt(walking,1);
}
void drawplayer(){
	gfx_TransparentSprite(stickman,p_pxl_x,p_pxl_y);
}
void keycheck(){
	kb_Scan();
	
	if ((kb_Data[7] & kb_Down)||(kb_Data[7] & kb_Left)||(kb_Data[7] & kb_Right)||(kb_Data[7] & kb_Up)){
		walking = 1;
	}
	else {
		walking = 0;
	}
		
}