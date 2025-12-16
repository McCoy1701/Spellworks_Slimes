#include <Archimedes.h>

#include "defines.h"
#include "map.h"
#include "structs.h"

static int PlayerDirection( void );
static void PlayerMovements( int key_value, float dt );

extern World_t world;

void PlayerInit( void )
{
  //Load animations
}

void PlayerLogic( float dt )
{
  world.player->facing = PlayerDirection();
  PlayerMovements( world.player->facing, dt );

}

static void PlayerMovements( int key_value, float dt )
{
  int dx = 0;
  int dz = 0;

  int speed = world.player->speed;

  switch ( key_value )
  {
    case FACING_NORTH: dx =  speed; break;
    case FACING_EAST:  dz =  speed; break;
    case FACING_SOUTH: dx = -speed; break;
    case FACING_WEST:  dz = -speed; break;
    
    case FACING_NORTH_EAST: dx =  speed; dz =  speed; break;
    case FACING_SOUTH_EAST: dx = -speed; dz =  speed; break;
    case FACING_SOUTH_WEST: dx = -speed; dz = -speed; break;
    case FACING_NORTH_WEST: dx =  speed; dz = -speed; break;
  }

  world.player->x += ( dx * dt );
  world.player->z += ( dz * dt );
}

static int PlayerDirection( void )
{
  int up    = app.keyboard[A_W] || app.keyboard[A_UP];
  int down  = app.keyboard[A_S] || app.keyboard[A_DOWN];
  int right = app.keyboard[A_D] || app.keyboard[A_RIGHT];
  int left  = app.keyboard[A_A] || app.keyboard[A_LEFT];

  uint8_t direction_bitmask = ( up << 0 | down << 1 | right << 2 | left << 3 );

  switch ( direction_bitmask )
  {
    case 0b0001: return FACING_NORTH;
    case 0b0010: return FACING_SOUTH;
    case 0b0100: return FACING_EAST;
    case 0b1000: return FACING_WEST;
    
    case 0b1001: return FACING_NORTH_WEST;
    case 0b1010: return FACING_SOUTH_WEST;
    case 0b0101: return FACING_NORTH_EAST;
    case 0b0110: return FACING_SOUTH_EAST;
  }

  return FACING_NONE;
}

