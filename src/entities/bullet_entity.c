#include <Archimedes.h>

#include "defines.h"
#include "structs.h"

extern World_t world;

void BulletEntityInit( Entity_t* e )
{
  e->img = a_ImageLoad( "resources/assets/bullet.png" );
  e->base = 10;
  dVec3_t pos = {0};
  float mass = 10;
  float max_speed = 4;
  float max_force = 0.4;

  e->body = d_KinematicBodyCreate( pos, 
                                   mass, 
                                   max_speed, 
                                   max_force );
  e->facing = world.player->facing;
  STRNCPY( e->name, "bullet", MAX_NAME_LENGTH );

}

