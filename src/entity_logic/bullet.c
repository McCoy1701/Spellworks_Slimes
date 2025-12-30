#include <Archimedes.h>

#include "defines.h"
#include "entity.h"
#include "entity_factory.h"
#include "iso.h"
#include "map.h"
#include "structs.h"
#include "utils.h"

extern World_t world;

void BulletInit( void )
{
  int w = 16;
  int h = 16;
  int frame_count = 4;
  uint32_t frame_duration = 100;
  
  Entity_t* e = ProjectileInit( "bullet_entity" );
  
  e->running[0] = a_AnimationCreate( 
    "resources/assets/projectiles/bullet/Bullet_SheetR.png",
    w, h, frame_count, frame_duration );
  
  e->running[1] = a_AnimationCreate(
    "resources/assets/projectiles/bullet/Bullet_SheetL.png",
    w, h, frame_count, frame_duration );
  
  e->running[2] = a_AnimationCreate( 
    "resources/assets/projectiles/bullet/Bullet_SheetU.png",
    w, h, frame_count, frame_duration );
  
  e->running[3] = a_AnimationCreate(
    "resources/assets/projectiles/bullet/Bullet_SheetD.png",
    w, h, frame_count, frame_duration );
  
  e->x = world.player->x;
  e->z = world.player->z;
}

void BulletLogic( float dt )
{
  Entity_t* e;
  for ( int i = 0; i < world.projectile_pool->count; i++ )
  {
    e = (Entity_t*)d_ArrayGet( world.projectile_pool, i );
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

