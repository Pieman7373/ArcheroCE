#ifndef __STRUCTS_H_
#define __STRUCTS_H_

#define MAX_BULLETS 3
#define BULLET_TYPE
#define BULLET_ALIVE
#define BULLET_SPEED
#define BULLET_VX
#define BULLET_VY
#define BULLET_X
#define BULLET_Y
typedef struct bullets {
	int bullet_type;
	int bullet_alive;
	int bullet_speed;
	int bullet_vx;
	int bullet_vy;
	uint16_t bullet_x;
	uint8_t bullet_y;
} bullets_t

#endif