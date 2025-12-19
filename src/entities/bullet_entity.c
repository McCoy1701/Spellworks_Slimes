#include <Archimedes.h>

#include "defines.h"
#include "structs.h"

extern World_t world;

void BulletEntityInit( Entity_t* e )
{
  e->img = a_ImageLoad( "resources/assets/bullet.png" );
  e->base = 35;
  e->speed = 4;
  e->facing = world.player->facing;

}

