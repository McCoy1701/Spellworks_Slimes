#ifndef __DEFINES_H__
#define __DEFINES_H__

#define CELL_WIDTH 32
#define CELL_HEIGHT 16

#define MAP_SIZE 24

#define MAP_RENDER_X_OFFSET ( ( SCREEN_WIDTH - ( CELL_WIDTH * MAP_SIZE ) ) / 2 )
#define MAP_RENDER_Y_OFFSET 425

#define SPRITE_TILE_WIDTH 13
#define SPRITE_TILE_HEIGHT 8

#define MAX_TILES 1024
#define MAX_ISO_OBJECTS 1024
#define ISO_RENDER_SPEED 15

#define INDEX_3( x, y, z, width, height ) ( ( z * ( width * height ) )\
    + ( y * height ) + x )

#define INDEX_2( x, y, height ) ( ( x * height ) + y )

#endif

