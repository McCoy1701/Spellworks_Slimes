#include <Archimedes.h>

#include "defines.h"
#include "structs.h"

extern World_t world;

void BaseEnemyEntityInit( Entity_t* e )
{
  e->img = a_ImageLoad( "resources/assets/enemy.png" );
  e->base = 35;
  
  dVec3_t gravity  = {0};
  dVec3_t velocity = {0};
  dVec3_t force    = {0};

  float   mass          = 10.0f;
  float   max_speed     = 8.0f;
  float   max_force     = 0.2f;
  uint8_t takes_gravity = 1;

  float   static_friction = 0.0f;
  float   dynamic_friction = 0.0f;
  float   restitution = 0.0f;

  e->body = d_KinematicBodyCreate( gravity, velocity,
                                   force, mass,
                                   max_speed, max_force,
                                   takes_gravity, 
                                   static_friction,
                                   dynamic_friction,
                                   restitution );

  e->state = STATE_IDLE;
  STRNCPY( e->name, "base_enemy", MAX_NAME_LENGTH );
}

