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
#include "projectiles.h"
#include "p_collision.h"

//tilemap pixel offsets
int tmp_pxl_x_offset = 0;
int tmp_pxl_y_offset = 0;
int n = 0;

//player screen coordinates in pixels
int p_pxl_x = 100;
int p_pxl_y = 100;
int walking = 0;
int walkstep = 3;
int frames = 0;
int framemax = 16;
//int framemax = 0;
int visiblebullets = 0;
int godown;
int goleft;
int goup;
int goright;
int p_projectile_speed = 1;

extern int bullet_number;
extern int bullet_outside;
extern gfx_tilemap_t tilemap;
//extern bullets_t bullets[];

void mainloop() {
	do {
		
		playerattack();
			gfx_SetDrawBuffer();
				drawmap();
				drawplayer();
				updatebullets();
			gfx_SwapDraw();
		keycheck();
		framecount();
	} while (!(kb_Data[6] & kb_Clear));
}

void drawmap(){
	gfx_FillScreen(0x00);
	gfx_Tilemap(&tilemap,tmp_pxl_x_offset,tmp_pxl_y_offset);
	/*
		gfx_SetTextFGColor(0xfe);
		gfx_SetTextXY(0,0);
		gfx_PrintInt(walking,1);
	*/
	gfx_SetTextFGColor(0xfe);
	gfx_SetTextXY(0,0);
	gfx_PrintInt(visiblebullets,2);
	gfx_SetTextXY(0,10);
	gfx_PrintInt(bullet_outside,1);
}
void playerattack(){
	
	int random;
	extern int user;
	
	if (walking == 0){
		if (frames == framemax){
			if (bullet_number <= MAX_BULLETS){
				if (visiblebullets <= MAX_BULLETS) {
					
					user = 1;
					checkbullets();
					
						if (bullet_outside == 0){
							bullet_number++;
							visiblebullets++;									
							n = (bullet_number);
							bullets[n].b_alive = 1;
							bullets[n].b_speed = p_projectile_speed;
							bullets[n].b_x = p_pxl_x;
							bullets[n].b_y = p_pxl_y;
						}
								
					//randomness is for testing only
					//add enemy distance and required projectile velocities functions
					random = (rand() % (4 - 0) + 0);
					if (random == 0) {
						bullets[n].b_vx = -1;
						bullets[n].b_vy = -1;
					}
					if (random == 1) {
						bullets[n].b_vx = 1;
						bullets[n].b_vy = -1;
					}
					if (random == 2) {
						bullets[n].b_vx = 1;
						bullets[n].b_vy = 1;
					}
					if (random == 3) {
						bullets[n].b_vx = -1;
						bullets[n].b_vy = 1;
					}

				}
			}
		}
	}
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
	if (kb_Data[7] & kb_Down) {
		godown = 0;
		pcollisiondown();
		if (godown == 1){p_pxl_y = (p_pxl_y + walkstep);}
	}
	if (kb_Data[7] & kb_Left) {
		goleft = 0;
		pcollisionleft();
		if (goleft == 1){p_pxl_x = (p_pxl_x - walkstep);}
	}
	if (kb_Data[7] & kb_Up) {
		goup = 0;
		pcollisionup();
		if (goup == 1){p_pxl_y = (p_pxl_y - walkstep);}
	}
	if (kb_Data[7] & kb_Right) {
		goright = 0;
		pcollisionright();
		if (goright == 1){p_pxl_x = (p_pxl_x + walkstep);}
	}
		
}
void framecount(){
	frames++;
	if (frames > framemax) {frames = 0;}
}