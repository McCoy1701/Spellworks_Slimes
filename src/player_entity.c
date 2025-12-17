#include <Archimedes.h>

#include "defines.h"
#include "structs.h"

extern World_t world;

void PlayerEntityInit( Entity_t* e )
{
  e->img = a_ImageLoad( "resources/assets/CharacterTest.png" );
  e->base = 35;
  e->speed = 2;
  app.options.scale_factor = 1;

  world.player = e;
}

