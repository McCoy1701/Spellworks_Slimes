#ifndef __STRUCTS_H__
#define __STRUCTS_H__

#include <Archimedes.h>
#include <Daedalus.h>

#include "defines.h"

typedef struct _entity
{
  char name[MAX_NAME_LENGTH];
  float x;
  float z;
  float speed;
  int base;
  int layer;
  int dead;
  int state;
  unsigned long flags;
  unsigned long iso_flags;
  aAnimation_t* running[FACING_MAX];
  aAnimation_t* idle;
  aImage_t* img;
  int facing;
  void ( *touch )( struct _entity* self, struct _entity* other );
  struct _entity* next;
}Entity_t;

typedef struct
{
  float x;  //world space
  float y;
  float sx;  //screen space
  float sy;
  int layer;
  int animated;
  aImage_t* img;
  aAnimation_t* anim;
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

typedef struct _Entity_Init_Func
{
  char name[MAX_NAME_LENGTH];
  void (*init)(Entity_t* e);
  struct _Entity_Init_Func* next;
} Entity_Init_Func_t;

#endif

