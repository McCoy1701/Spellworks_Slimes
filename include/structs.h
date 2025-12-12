#ifndef __STRUCTS_H__
#define __STRUCTS_H__

#include <Archimedes.h>
#include <Daedalus.h>

#include "defines.h"

typedef struct _entity
{
  char name[MAX_NAME_LENGTH];
  int x;
  int z;
  int base;
  int layer;
  int dead;
  unsigned long flags;
  unsigned long iso_flags;
  aImage_t* img;
  dVec2_t facing;
  void ( *touch )( struct _entity* self, struct _entity* other );
  struct _entity* next;
}Entity_t;

typedef struct
{
  int x;  //world space
  int y;
  int sx;  //screen space
  int sy;
  int layer;
  aImage_t* img;
  aColor_t color;
} ISO_Object_t;

typedef struct
{
  int tile;
} Map_Tile_t;

typedef struct
{
  Map_Tile_t map[MAP_SIZE * MAP_SIZE];
  Entity_t entity_head, *entity_tail;
  Entity_t* player;
  aRectf_t player_iso_rect;
  int cursor_x, cursor_y;
} World_t;

#endif

