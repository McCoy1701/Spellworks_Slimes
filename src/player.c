#include <Archimedes.h>

#include "defines.h"
#include "map.h"
#include "structs.h"

static int PlayerDirection( void );
static void PlayerMovements( int key_value );

extern World_t world;

void PlayerInit( void )
{
  //Load animations
}

void PlayerLogic( float dt )
{
  world.player->facing = PlayerDirection();
  PlayerMovements( world.player->facing );

}

static void PlayerMovements( int key_value )
{
  switch ( key_value )
  {
    case FACING_NORTH:
      world.player->x++;
      break;
    
    case FACING_NORTH_EAST:
      world.player->x++;
      world.player->z++;
      break;
    
    case FACING_EAST:
      world.player->z++;
      break;
    
    case FACING_SOUTH_EAST:
      world.player->x--;
      world.player->z++;
      break;
    
    case FACING_SOUTH:
      world.player->x--;
      break;
    
    case FACING_SOUTH_WEST:
      world.player->x--;
      world.player->z--;
      break;
    
    case FACING_WEST:
      world.player->z--;
      break;
    
    case FACING_NORTH_WEST:
      world.player->x++;
      world.player->z--;
      break;
    
    default:
      break;
  }
}

static int PlayerDirection( void )
{
  if ( app.keyboard[A_W] || app.keyboard[A_UP] )
  {
    if ( app.keyboard[A_A] || app.keyboard[A_LEFT] )
    {
      app.keyboard[A_W]  = 0;
      app.keyboard[A_UP] = 0;
      app.keyboard[A_A]  = 0;
      return FACING_NORTH_WEST;
    }
    
    else if( app.keyboard[A_D] || app.keyboard[A_RIGHT] )
    {
      app.keyboard[A_W]  = 0;
      app.keyboard[A_UP] = 0;
      app.keyboard[A_D]  = 0;
      return FACING_NORTH_EAST;
    }

    app.keyboard[A_W] = 0;
    app.keyboard[A_UP] = 0;
    return FACING_NORTH;
  }
  
  if ( app.keyboard[A_S] || app.keyboard[A_DOWN] )
  {
    if ( app.keyboard[A_A] || app.keyboard[A_LEFT] )
    {
      app.keyboard[A_S]  = 0;
      app.keyboard[A_DOWN] = 0;
      app.keyboard[A_A]  = 0;
      return FACING_SOUTH_WEST;
    }
    
    else if( app.keyboard[A_D] || app.keyboard[A_RIGHT] )
    {
      app.keyboard[A_S]  = 0;
      app.keyboard[A_DOWN] = 0;
      app.keyboard[A_D]  = 0;
      return FACING_SOUTH_EAST;

    }

    app.keyboard[A_DOWN] = 0;
    app.keyboard[A_S] = 0;
    return FACING_SOUTH;
  }
  
  if ( app.keyboard[A_A] || app.keyboard[A_LEFT] )
  {
    if ( app.keyboard[A_W] || app.keyboard[A_UP] )
    {
      app.keyboard[A_A] = 0;
      app.keyboard[A_W] = 0;
      app.keyboard[A_LEFT] = 0;
      return FACING_NORTH_WEST;
    }
    
    else if ( app.keyboard[A_S] || app.keyboard[A_DOWN] )
    {
      app.keyboard[A_A] = 0;
      app.keyboard[A_S] = 0;
      app.keyboard[A_LEFT] = 0;
      return FACING_SOUTH_WEST;
    }

    app.keyboard[A_A] = 0;
    app.keyboard[A_LEFT] = 0;
    return FACING_WEST;
  }
  
  if ( app.keyboard[A_D] || app.keyboard[A_RIGHT])
  {
    if ( app.keyboard[A_W] || app.keyboard[A_UP] )
    {
      app.keyboard[A_A] = 0;
      app.keyboard[A_W] = 0;
      app.keyboard[A_LEFT] = 0;
      return FACING_NORTH_EAST;
    }
    else if ( app.keyboard[A_S] || app.keyboard[A_DOWN] )
    {
      app.keyboard[A_A] = 0;
      app.keyboard[A_S] = 0;
      app.keyboard[A_LEFT] = 0;
      return FACING_SOUTH_EAST;
    }

    app.keyboard[A_D] = 0;
    app.keyboard[A_RIGHT] = 0;
    return FACING_EAST;
  }

  return FACING_NONE;
}

