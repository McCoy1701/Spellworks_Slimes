#include <Archimedes.h>

#include "defines.h"
#include "structs.h"

extern World_t world;

void PlayerEntityInit( Entity_t* e )
{
  e->img = a_ImageLoad( "resources/assets/CharacterTest.png" );
  e->base = 35;
  
  dVec3_t pos = {0};
  float mass = 10;
  float max_speed = 2;
  float max_force = 0.2;

  e->body = d_KinematicBodyCreate( pos, 
                                   mass, 
                                   max_speed, 
                                   max_force );
  e->facing = FACING_SOUTH;
  e->state = STATE_IDLE;
  STRNCPY( e->name, "player", MAX_NAME_LENGTH );

  world.player = e;
}

