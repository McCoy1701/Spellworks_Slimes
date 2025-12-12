#include <Archimedes.h>

#include "defines.h"
#include "image.h"
#include "iso.h"
#include "structs.h"

extern World_t world;

static aImage_t* tiles[MAX_TILES];
static aImage_t* selected_tile;

void Map_Init( void )
{
  for ( int i = 0; i < MAP_SIZE; i++ )
  {
    for ( int j = 0; j < MAP_SIZE; j++ )
    {
      int index = INDEX_2( i, j, MAP_SIZE );
      world.map[index].tile = 0;
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
      int index = INDEX_2( i, j, MAP_SIZE );
      n = world.map[index].tile;

      if ( n >= 0 )
      {
        if ( i == world.cursor_x && j == world.cursor_y )
        {
          ISO_AddObject( i, j, 0, 0, selected_tile );
        }

        else
        {
          ISO_AddObject( i, j, 0, 0, tiles[n] );
        }
      }
    }
  }

}

