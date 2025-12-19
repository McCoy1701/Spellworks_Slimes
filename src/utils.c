
#include <Archimedes.h>

#include "structs.h"

void CalculateScreenPos( Entity_t* e, int* sx, int* sy )
{
  *sx = CELL_WIDTH / 2;
  *sx -= e->img->rect.w / 2;
  
  *sy = CELL_HEIGHT / 2;
  *sy -= e->img->rect.h;
  *sy -= e->base;
}

void LoadAnimation( int w, int h, int frame_count,
                    uint32_t frame_duration,
                    char* filename, aAnimation_t** anim )
{
  
  //Load animations
  for ( int i = FACING_NONE; i < FACING_MAX; i++ )
  {
    char anim_name[MAX_FILENAME_LENGTH];
    char id_name[6];
    
    snprintf( id_name, 6, "%d.png", i );
    
    strcat( anim_name, filename );
    strcat( anim_name, id_name );
    
    anim[i] = a_AnimationCreate( anim_name, w, h,
                                 frame_count, frame_duration );
    
    memset( anim_name, 0, MAX_FILENAME_LENGTH );
  }

}

