#include <Archimedes.h>

#include "defines.h"
#include "map.h"
#include "structs.h"

static void PlayerMovements( int key_value0, int key_value1, int* axis, int delta );

extern World_t world;

void PlayerInit( void )
{
  //Load animations
}

void PlayerLogic( float dt )
{
  PlayerMovements( A_W, A_UP, &world.player->x, 1 );
  PlayerMovements( A_S, A_DOWN, &world.player->x, -1 );
  PlayerMovements( A_D, A_RIGHT, &world.player->z, 1 );
  PlayerMovements( A_A, A_LEFT, &world.player->z, -1 );

}

static void PlayerMovements( int key_value0, int key_value1, int* axis, int delta )
{
  if ( app.keyboard[key_value0] || app.keyboard[key_value1] )
  {
    app.keyboard[key_value0] = 0;
    app.keyboard[key_value1] = 0;
    
    if ( CheckPlayersBounds() )
    {
      *axis += delta;
    }
  }
}

