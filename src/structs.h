#ifndef __STRUCTS_H_
#define __STRUCTS_H_

#define MAX_BULLETS 3
#define B_TYPE
#define B_ALIVE
#define B_SPEED
#define B_VX
#define B_VY
#define B_X
#define B_Y
typedef struct bullets {
	int b_type;
	int b_alive;
	int b_speed;
	int b_vx;
	int b_vy;
	uint16_t b_x;
	uint8_t b_y;
} bullets_t;

extern bullets_t bullets[];

#endif