#include <Archimedes.h>

#include "defines.h"
#include "entity_factory.h"
#include "iso.h"
#include "map.h"
#include "structs.h"
#include "utils.h"

extern World_t world;

static void AddEntities( void );
static void PlaceRandom( int* x, int* z );

void EntitiesInit( void )
{
  world.entity_pool = d_ArrayInit( MAX_ENTITIES, sizeof( Entity_t ) );
  world.projectile_pool = d_ArrayInit( MAX_PROJECTILES, sizeof( Entity_t ) );

  AddEntities();
}

void EntitiesDraw( void )
{
  Entity_t* e;
  int sx, sy;

  for ( int i = 0; i < world.entity_pool->count; i++ )
  {
    e = (Entity_t*)d_ArrayGet( world.entity_pool, i );
    if ( e == NULL ) continue;
    
    if ( e->dead )
    {
      EntityPoolRemove( e );
      continue;
    }

    CalculateScreenPos( e, &sx, &sy );
    if ( e ==  world.player )
    {
      if ( e->state == STATE_RUN )
      {
        ISO_AddAnimatedObject(e->x, e->z, sx, sy, e->running[e->facing], LAYER_MID );
      }
      
      else if ( e->state == STATE_IDLE )
      {
        ISO_AddAnimatedObject(e->x, e->z, sx, sy, e->idle[e->facing], LAYER_MID );
      }
    }
    
    else
    {
      ISO_AddStaticObject( e->x, e->z, sx, sy, e->img, LAYER_MID );
    }
  }
}

Entity_t* EntitiesAt( int x, int z )
{
  Entity_t* e;
  for ( int i = 0; i < world.entity_pool->count; i++ )
  {
    e = (Entity_t*)d_ArrayGet( world.entity_pool, i );
    if ( e == NULL ) return NULL;
    
    if ( e->x == x && e->z == z )
    {
      return e;
    }
  }

  return NULL;
}

static void AddEntities( void )
{
  Entity_t* e;
  int x, z;

  PlaceRandom( &x, &z );

  e = EntityInit( "player_entity" );
  e->x = x;
  e->z = z;
}

static void PlaceRandom( int* x, int* z )
{
  int ok;
  do
  {
    *x = rand() % MAP_SIZE;
    *z = rand() % MAP_SIZE;

    ok = IsGround( *x, *z ) && EntitiesAt( *x, *z ) == NULL;
  } while (!ok);
}

