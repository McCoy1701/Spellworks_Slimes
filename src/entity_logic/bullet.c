#include <Archimedes.h>

#include "defines.h"
#include "entity.h"
#include "entity_factory.h"
#include "iso.h"
#include "map.h"
#include "structs.h"

extern World_t world;

void BulletInit( void )
{
  Entity_t* e = EntityInit( "bullet_entity" );
  e->x = world.player->x;
  e->z = world.player->z;
}

void BulletLogic( float dt )
{
  Entity_t* e;
  for ( int i = 0; i < world.entity_count; i++ )
  {
    e = (Entity_t*)d_ArrayGet( world.entity_pool, i );
    if ( e == NULL ) continue;
    
    if ( strncmp( e->name, "bullet", MAX_NAME_LENGTH ) == 0 )
    {
      if ( CheckMapBounds( e->x, e->z ) )
      {
        int dx = 0;
        int dz = 0;

        int speed = e->speed;

        switch ( e->facing )
        {
          case FACING_NORTH: dx =  speed; break;
          case FACING_EAST:  dz =  speed; break;
          case FACING_SOUTH: dx = -speed; break;
          case FACING_WEST:  dz = -speed; break;

          case FACING_NORTH_EAST: dx =  speed; dz =  speed; break;
          case FACING_SOUTH_EAST: dx = -speed; dz =  speed; break;
          case FACING_SOUTH_WEST: dx = -speed; dz = -speed; break;
          case FACING_NORTH_WEST: dx =  speed; dz = -speed; break;
        }

        e->x += ( dx * dt );
        e->z += ( dz * dt );
      }
      
      else
      {
        e->dead = 1;
      }
    }
  }
}

