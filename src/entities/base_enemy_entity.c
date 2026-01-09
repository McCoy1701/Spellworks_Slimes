#include <Archimedes.h>

#include "defines.h"
#include "structs.h"

extern World_t world;

void BaseEnemyEntityInit( Entity_t* e )
{
  e->img = a_ImageLoad( "resources/assets/enemy.png" );
  e->base = 35;
  dVec3_t pos = {0};
  float mass = 10;
  float max_speed = 1;
  float max_force = 0.4;

  e->body = d_KinematicBodyCreate( pos, 
                                   mass, 
                                   max_speed, 
                                   max_force );
  e->state = STATE_IDLE;
  STRNCPY( e->name, "base_enemy", MAX_NAME_LENGTH );
}

