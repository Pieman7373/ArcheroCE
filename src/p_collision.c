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

void pcollisiondown(){
	godown = 1;
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