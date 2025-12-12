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
#define ISO_RENDER_SPEED 250

#define INDEX_3( x, y, z, width, height ) ( ( z * ( width * height ) )\
    + ( y * height ) + x )

#define INDEX_2( x, y, height ) ( ( x * height ) + y )

enum
{
  LAYER_BACKGROUND = 0,
  LAYER_MID = 8,
  LAYER_FOREGROUND = 15,
  LAYER_MAX
};

enum
{
  FACING_NORTH,
  FACING_NORTH_EAST,
  FACING_EAST,
  FACING_SOUTH_EAST,
  FACING_SOUTH,
  FACING_SOTUH_WEST,
  FACING_WEST,
  FACING_NORTH_WEST
};

#endif

