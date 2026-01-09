#include <Archimedes.h>
#include <Daedalus.h>

#include "defines.h"
#include "structs.h"

extern World_t world;

static int draw_comparator( const void* a, const void* b );

static int iso_object_count;
static ISO_Object_t iso_objects[MAX_ISO_OBJECTS];
static ISO_Object_t* render_list[MAX_ISO_OBJECTS];
static double iso_draw_timer;

void ISO_Init( void )
{
  iso_draw_timer = 0;
}

void ISO_Logic( float dt )
{
  iso_draw_timer = MIN( iso_draw_timer + ISO_RENDER_SPEED * dt, iso_object_count );
  //iso_draw_timer = iso_object_count;
}

void ISO_Draw( void )
{
  for ( int i = 0; i < iso_object_count; i++ )
  {
    render_list[i] = &iso_objects[i];
  }

  qsort( render_list, iso_object_count, sizeof( ISO_Object_t* ), draw_comparator );

  for ( int i = 0; i < iso_object_count; i++ )
  {
    ISO_Object_t* obj = render_list[i];
    if ( iso_draw_timer >= i )
    {
      if ( obj->animated )
      {
        aPoint2f_t pos = (aPoint2f_t){ .x = obj->sx,
                                       .y = obj->sz };
        a_AnimationPlay( pos, obj->anim );
      }
      
      else
      {
        obj->img->color = obj->color;
        obj->img->color_modulate = obj->modulate_color;
        
        a_Blit( obj->img, obj->sx, obj->sz );
      }
    }
  }
}

void ISO_Clear( void )
{
  memset( iso_objects, 0, ( sizeof( ISO_Object_t ) * iso_object_count ) );
  memset( render_list, 0, ( sizeof( ISO_Object_t* ) * iso_object_count ) );
  iso_object_count = 0;
}

void ISO_Convert( dVec3_t pos, float* sx, float* sz )
{
  *sx = MAP_RENDER_X_OFFSET + ( ( pos.x * CELL_WIDTH / 2 ) + ( pos.z * CELL_WIDTH / 2 ) );
  *sz = MAP_RENDER_Y_OFFSET + ( ( pos.z * CELL_HEIGHT / 2 ) - ( pos.x * CELL_HEIGHT / 2 ) );
}

void ISO_AddAnimatedObject( dVec3_t pos, float sx, float sz,
                            aAnimation_t* anim, int layer )
{
  ISO_Object_t* o;
  if ( iso_object_count < MAX_ISO_OBJECTS )
  {
    o = &iso_objects[iso_object_count++];
    ISO_Convert( pos, &o->x, &o->z );

    o->sx = o->x + sx;
    o->sz = o->z + sz;
    o->layer = layer;
    o->anim = anim;
    o->animated = 1;
  }
}

void ISO_AddStaticObject( dVec3_t pos, float sx, float sy, aImage_t* img,
                          int layer )
{
  ISO_Object_t* o;

  if ( iso_object_count < MAX_ISO_OBJECTS )
  {
    o = &iso_objects[iso_object_count++];
    ISO_Convert( pos, &o->x, &o->z );

    o->sx = o->x + sx;
    o->sz = o->z + sy;
    o->layer = layer;
    o->img = img;
    o->modulate_color = img->color_modulate;
    o->color = img->color;
  }
}

int ISO_CheckBounds( dVec3_t pos )
{
  float min_x, min_y;
  float max_x, max_y;
  dVec3_t zero_pos = {0};
  dVec3_t map_max_pos = (dVec3_t){ .x = MAP_SIZE, .z = MAP_SIZE };
  
  ISO_Convert( zero_pos, &min_x, &min_y );
  ISO_Convert( map_max_pos, &max_x, &max_y );

  return ( pos.x >= 0 &&
           pos.z >= 0 && 
           pos.x <= max_x &&
           pos.z <= max_y );
}

static int draw_comparator( const void* a, const void* b )
{
  ISO_Object_t* o1, *o2;
  o1 = *(ISO_Object_t**)a;
  o2 = *(ISO_Object_t**)b;
  if ( o1->z < o2->z ) return -1;
  if ( o1->z > o2->z ) return 1;
  return 0;
}

