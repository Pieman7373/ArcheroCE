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


extern gfx_tilemap_t tilemap;
int i;
int bullet_number;
int bullet_x;
int bullet_y;
int bullet_outside;
int user = 0;
int whydoihavetodothis = 1;
extern int visiblebullets;
extern int n;

void updatebullets(){
	
	if (bullet_number >= MAX_BULLETS) {
		bullet_number = 0;
	}
	
	for (i=0;i < visiblebullets;i++){
		if ((bullets[i].b_alive) == 1){
			bullets[i].b_x = ((bullets[i].b_x) + ((bullets[i].b_vx)*(bullets[i].b_speed)));
			bullets[i].b_y = ((bullets[i].b_y) + ((bullets[i].b_vy)*(bullets[i].b_speed)));
			
			user = 2;
			checkbullets();
				
			if (bullets[i].b_alive == 1) {
				renderbullets();
			}
		}
	}
}

void renderbullets(){
	gfx_TransparentSprite(test_bullet,bullets[i].b_x,bullets[i].b_y);
}

void checkbullets(){
	extern int bullet_outside;
	int element = 0;
/*
bullets[i].b_x > (TILEMAP_POS_X + (TILEMAP_DRAW_WIDTH * TILEMAP_TILE_SIZE))
bullets[i].b_y > (TILEMAP_POS_Y + (TILEMAP_DRAW_HEIGHT * TILEMAP_TILE_SIZE))
bullets[i].b_x < TILEMAP_POS_X
bullets[i].b_y < TILEMAP_POS_Y
*/
	
	bullet_outside = 0;
	if (user == 1){element = n;}
	if (user == 2){element = i;}
	
	if (bullets[element].b_x > ((TILEMAP_POS_X + (TILEMAP_DRAW_WIDTH * TILEMAP_TILE_SIZE)) - 16)){
		bullet_outside = 1;
	}
	else if (bullets[element].b_y > (TILEMAP_POS_Y + (TILEMAP_DRAW_HEIGHT * TILEMAP_TILE_SIZE))){
		bullet_outside = 1;
	}
	else if (bullets[element].b_x < TILEMAP_POS_X){
		bullet_outside = 1;
	}
	else if (bullets[element].b_y < TILEMAP_POS_Y){
		bullet_outside = 1;
	}
	
	
	if ((n == 0) && (whydoihavetodothis == 1)){
		bullet_outside = 0;
		whydoihavetodothis++;
	}
	
		
	if (bullet_outside == 1){
		visiblebullets--;
			if (visiblebullets < 0){visiblebullets = 0;}
		bullets[element].b_alive = 0;
	}
}