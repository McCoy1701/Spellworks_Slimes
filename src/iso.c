
#include <Archimedes.h>

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
                                       .y = obj->sy };
        a_AnimationPlay( pos, obj->anim );
      }
      
      else
      {
        obj->img->color = obj->color;
        obj->img->color_modulate = obj->modulate_color;
        
        a_Blit( obj->img, obj->sx, obj->sy );
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

void ISO_Convert( float x, float z, float* sx, float* sy )
{
  *sx = MAP_RENDER_X_OFFSET + ( ( x * CELL_WIDTH / 2 ) + ( z * CELL_WIDTH / 2 ) );
  *sy = MAP_RENDER_Y_OFFSET + ( ( z * CELL_HEIGHT / 2 ) - ( x * CELL_HEIGHT / 2 ) );
}

void ISO_AddAnimatedObject( float x, float z, float sx, float sy, aAnimation_t* anim, int layer )
{
  ISO_Object_t* o;
  if ( iso_object_count < MAX_ISO_OBJECTS )
  {
    o = &iso_objects[iso_object_count++];
    ISO_Convert( x, z, &o->x, &o->y );

    o->sx = o->x + sx;
    o->sy = o->y + sy;
    o->layer = layer;
    o->anim = anim;
    o->animated = 1;
  }
}

void ISO_AddStaticObject( float x, float z, float sx, float sy, aImage_t* img, int layer )
{
  ISO_Object_t* o;

  if ( iso_object_count < MAX_ISO_OBJECTS )
  {
    o = &iso_objects[iso_object_count++];

    ISO_Convert( x, z, &o->x, &o->y );

    o->sx = o->x + sx;
    o->sy = o->y + sy;
    o->layer = layer;
    o->img = img;
    o->modulate_color = img->color_modulate;
    o->color = img->color;
  }
}

int ISO_CheckBounds( float x, float z )
{
  float min_x, min_y;
  float max_x, max_y;
  ISO_Convert( 0, 0, &min_x, &min_y );
  ISO_Convert( MAP_SIZE, MAP_SIZE, &max_x, &max_y );

  return ( x >= 0 &&
           z >= 0 && 
           x <= max_x &&
           z <= max_y );
}

static int draw_comparator( const void* a, const void* b )
{
  ISO_Object_t* o1, *o2;
  o1 = *(ISO_Object_t**)a;
  o2 = *(ISO_Object_t**)b;
  if ( o1->y < o2->y ) return -1;
  if ( o1->y > o2->y ) return 1;
  return 0;
}

