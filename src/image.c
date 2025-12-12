#include <Archimedes.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>

#include "defines.h"

void load_tiles( aImage_t** img_cache,
                 int width, int height,
                 int cell_width, int cell_height,
                 const char* filename )
{
  int temp_x = 0, temp_y = 0;
  aImage_t* master = a_ImageLoad( filename );

  for ( int i = 0; i < width; i++ )
  {
    temp_x = i * cell_width;
    for ( int j = 0; j < height; j++ )
    {
      int index = INDEX_2( i, j, height );
      temp_y = j * cell_height;

      aRectf_t src_rect = (aRectf_t){
        .x = temp_x,
        .y = temp_y,
        .w = cell_width,
        .h = cell_height,
      };
      
      aRectf_t dest_rect = (aRectf_t){
        .x = 0,
        .y = 0,
        .w = cell_width,
        .h = cell_height,
      };
      
      aImage_t* temp_img = malloc( sizeof( aImage_t ) );
      if ( temp_img == NULL )
      {
        LOG( "Failed to allocate memory for img_cache" );
        return;
      }

      temp_img->surface = SDL_CreateRGBSurface(
        0,
        cell_width,
        cell_height,
        master->surface->format->BitsPerPixel,
        master->surface->format->Rmask,
        master->surface->format->Gmask,
        master->surface->format->Bmask,
        master->surface->format->Amask
      );
      
      a_BlitSurfaceToSurfaceScaled( master, &src_rect, temp_img, &dest_rect, 1.0f );
      
      img_cache[index] = temp_img;
    }
  }
}

