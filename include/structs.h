#ifndef __STRUCTS_H__
#define __STRUCTS_H__

#include <Archimedes.h>

#include "defines.h"

typedef struct
{
  int x;  //world space
  int y;
  int sx;  //screen space
  int sy;
  aImage_t* img;
} ISO_Object_t;

typedef struct
{
  int tile;
} Map_Tile_t;

typedef struct
{
  Map_Tile_t map[MAP_SIZE];
  int cursor_x, cursor_y;
} World_t;

#endif

