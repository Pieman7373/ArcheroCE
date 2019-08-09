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


//extern bullets_t bullets[];
extern gfx_tilemap_t tilemap;
int i;
int bullet_number;
int bullet_x;
int bullet_y;

void updatebullets(){
	bullet_number = 0;
	for (i=0;i<MAX_BULLETS;i++){
		if ((bullets[i].b_alive) == 1){
			bullets[i].b_x = ((bullets[i].b_x) + ((bullets[i].b_vx)*(bullets[i].b_speed)));
			bullets[i].b_y = ((bullets[i].b_y) + ((bullets[i].b_vy)*(bullets[i].b_speed)));
			bullet_number++;
			if ((bullets[i].b_x > ((TILEMAP_POS_X + TILEMAP_DRAW_HEIGHT)*(TILEMAP_TILE_SIZE)))||(bullets[i].b_y > ((TILEMAP_POS_Y + TILEMAP_DRAW_WIDTH)*(TILEMAP_TILE_SIZE)))||(bullets[i].b_x < TILEMAP_POS_X)||(bullets[i].b_y < TILEMAP_POS_Y)){
			bullets[i].b_alive = 0;
				bullet_number--;
			}
			if (bullets[i].b_alive == 1) {
				renderbullets();
			}
		}
	}
}
void renderbullets(){
	gfx_TransparentSprite(test_bullet,bullets[i].b_x,bullets[i].b_y);
}