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
  
  e->transform->position.x = world.player->transform->position.x;
  e->transform->position.z = world.player->transform->position.z;
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
      if ( CheckMapBounds( e->transform->position.x,
                           e->transform->position.z ) )
      {
        dVec3_t dvec = {0};

        int speed = e->body->max_speed;
        switch ( e->facing )
        {
          case FACING_NORTH: dvec.x =  speed; break;
          case FACING_EAST:  dvec.z =  speed; break;
          case FACING_SOUTH: dvec.x = -speed; break;
          case FACING_WEST:  dvec.z = -speed; break;

          case FACING_NORTH_EAST: dvec.x =  speed; dvec.z =  speed; break;
          case FACING_SOUTH_EAST: dvec.x = -speed; dvec.z =  speed; break;
          case FACING_SOUTH_WEST: dvec.x = -speed; dvec.z = -speed; break;
          case FACING_NORTH_WEST: dvec.x =  speed; dvec.z = -speed; break;
        }

        d_ScaleMultiplyVec3f( &dvec, dvec, dt );
        d_KinematicBodyApplyForce( e->body, dvec );
        d_KinematicBodyUpdate( e->body, e->transform, dt );
      }
      
      else
      {
        e->dead = 1;
      }
    }
  }
}

