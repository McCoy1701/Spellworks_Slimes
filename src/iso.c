
#include <Archimedes.h>

#include "defines.h"
#include "structs.h"

static int draw_comparator( const void* a, const void* b );

static int iso_object_count;
static ISO_Object_t iso_objects[MAX_ISO_OBJECTS];
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
  ISO_Object_t* o;

  qsort( iso_objects, iso_object_count, sizeof( ISO_Object_t ), draw_comparator );

  for ( int i = 0; i < iso_object_count; i++ )
  {
    if ( iso_draw_timer >= i )
    {
      o = &iso_objects[i];
      if ( o->animated )
      {
        aPoint2f_t pos = (aPoint2f_t){ .x = o->sx, .y = o->sy };
        a_AnimationPlay( pos, o->anim );
      }
      
      else
      {
        a_Blit( o->img, o->sx, o->sy );
      }
    }
  }
}

void ISO_Clear( void )
{
  memset( iso_objects, 0, ( sizeof( ISO_Object_t ) * iso_object_count ) );
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
  o1 = (ISO_Object_t*)a;
  o2 = (ISO_Object_t*)b;
  return o1->y - o2->y;
}

