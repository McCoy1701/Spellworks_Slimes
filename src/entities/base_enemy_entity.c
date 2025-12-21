#include <Archimedes.h>

#include "defines.h"
#include "structs.h"

extern World_t world;

void BaseEnemyEntityInit( Entity_t* e )
{
  e->img = a_ImageLoad( "resources/assets/enemy.png" );
  e->base = 35;
  e->speed = 1;
  e->state = STATE_IDLE;
  STRNCPY( e->name, "base_enemy", MAX_NAME_LENGTH );
}

