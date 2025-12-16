#include <Archimedes.h>

#include "defines.h"
#include "structs.h"

extern World_t world;

void PlayerEntityInit( Entity_t* e )
{
  e->img = a_ImageLoad( "resources/assets/CharacterTest.png" );
  e->base = 13;
  e->speed = 1;

  world.player = e;
}

