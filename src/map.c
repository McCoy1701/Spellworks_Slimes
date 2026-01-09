#include <Archimedes.h>

#include "defines.h"
#include "image.h"
#include "iso.h"
#include "structs.h"

extern World_t world;

static aImage_t* tiles[MAX_TILES];
static aImage_t* selected_tile;

int half = MAP_SIZE / 2;

void Map_Init( void )
{
  for ( int i = 0; i < MAP_SIZE; i++ )
  {
    for ( int j = 0; j < MAP_SIZE; j++ )
    {
      int index = INDEX_2( i, j, MAP_SIZE );
      world.map[index].tile = 0;
      world.map[index].modulate_color = 0;
      world.map[index].color = white;
      
      if ( i == 0 && ( j >= (half - 1) && j <= (half + 2) ) )
      {
        world.map[index].modulate_color = 1;
        world.map[index].color = red;
      }
      if ( j == 0 && ( i >= (half - 1) && i <= (half + 2) ) )
      {
        world.map[index].modulate_color = 1;
        world.map[index].color = yellow;
      }
      if ( i == MAP_SIZE-1 && ( j >= (half - 1) && j <= (half + 2) ) )
      {
        world.map[index].modulate_color = 1;
        world.map[index].color = blue;
      }
      if ( j == MAP_SIZE-1 && ( i >= (half - 1) && i <= (half + 2) ) )
      {
        world.map[index].modulate_color = 1;
        world.map[index].color = cyan;
      }
    }
  }

  load_tiles( tiles, SPRITE_TILE_WIDTH, SPRITE_TILE_HEIGHT,
              32, 32, "resources/assets/IsoBlocks.png" );
  selected_tile = a_ImageLoad( "resources/assets/selected_tile.png" );
}

void Map_Draw( void )
{
  int n;

  for ( int i = 0; i < MAP_SIZE; i++ )
  {
    for ( int j = 0; j < MAP_SIZE; j++ )
    {
      dVec3_t pos = { .x = i, .y = 0, .z = j };

      int index = INDEX_2( i, j, MAP_SIZE );
      n = world.map[index].tile;

      if ( n >= 0 )
      {
        if ( i == world.cursor_x && j == world.cursor_y )
        {
          ISO_AddStaticObject( pos, 0, 0, selected_tile, LAYER_BACKGROUND );
        }

        else
        {
          aImage_t* img = tiles[n];
          img->color_modulate = world.map[index].modulate_color;
          img->color = world.map[index].color;
          ISO_AddStaticObject( pos, 0, 0, img, LAYER_BACKGROUND );
        }
      }
    }
  }

}

int IsGround( int x, int z )
{
  int index = INDEX_2( x, z, MAP_SIZE );
  return ( x >= 0 &&
           z >= 0 &&
           x < MAP_SIZE &&
           z < MAP_SIZE &&
           world.map[index].tile >= TILE_GROUND && 
           world.map[index].tile < TILE_WALL );
}

int CheckMapBounds( int x, int z )
{
  return ( x >= 0 &&
           z >= 0 && 
           x <= MAP_SIZE &&
           z <= MAP_SIZE );
}

int CheckPlayersBounds( void )
{
  return ( world.player->body->position.x >= 0 &&
           world.player->body->position.z >= 0 && 
           world.player->body->position.x <= MAP_SIZE &&
           world.player->body->position.z <= MAP_SIZE );
}
