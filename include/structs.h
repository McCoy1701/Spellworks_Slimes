#ifndef __STRUCTS_H__
#define __STRUCTS_H__

#include <Archimedes.h>
#include <Daedalus.h>

#include "defines.h"

typedef struct _entity
{
  char name[MAX_NAME_LENGTH];
  int id;
  
  dTransform_t* transform;
  uint8_t is_trigger;
  uint8_t is_static;
  uint8_t is_dynamic;

  dKinematicBody_t* body;
 
  int base;
  int layer;
 
  int dead;
  int state;
  unsigned long flags;
  unsigned long iso_flags;
 
  int facing;
  
  aAnimation_t* running[FACING_MAX];
  aAnimation_t* idle[FACING_MAX];
  aImage_t* img;
}Entity_t;

typedef struct _item_t
{
  char name[MAX_NAME_LENGTH];
  dTransform_t* transform;
  uint8_t is_trigger;
  uint8_t is_static;
  uint8_t is_dynamic;

  dKinematicBody_t* body;
  
  int base;
  int layer;
  
  int picked_up;
  int weight;
  unsigned long flags;
  
  aImage_t* img;
}Item_t;

typedef struct
{
  float x;
  float z;
  float sx;  //screen space
  float sz;
  
  int layer;
  int animated;
  
  aImage_t* img;
  aAnimation_t* anim;
  
  int modulate_color;
  aColor_t color;
} ISO_Object_t;

typedef struct
{
  int tile;
  int modulate_color;
  aColor_t color;
} Map_Tile_t;

typedef struct
{
  int tl_projectiles; //tl == total lifetime
  int tl_entities;
  int tl_ground_items;
  int tl_stage_count;
} Stats_t;

typedef struct
{
  Map_Tile_t map[MAP_SIZE * MAP_SIZE];
  dArray_t* entity_pool;
  dArray_t* projectile_pool;
  dArray_t* ground_item_pool;
  Stats_t stats;
  Entity_t* player;
  aRectf_t player_iso_rect;
  dVec3_t gravity; 
  int cursor_x, cursor_y;
  aTimer_t stage_timer;
} World_t;

typedef struct _Entity_Init_Func
{
  char name[MAX_NAME_LENGTH];
  void (*init)(Entity_t* e);
  struct _Entity_Init_Func* next;
} Entity_Init_Func_t;

typedef struct _Item_Init_Func
{
  char name[MAX_NAME_LENGTH];
  void (*init)(Item_t* e);
  struct _Item_Init_Func* next;
} Item_Init_Func_t;

typedef struct
{
  dArray_t* enemy_pool;
  aTimer_t* timer;
  uint32_t wait_ms;
} EnemySpawner_t;

#endif

