#include <Archimedes.h>

#include "defines.h"
#include "entity_factory.h"
#include "iso.h"
#include "structs.h"
#include "utils.h"

extern World_t world;

void ProjectileDraw( void )
{
  Entity_t* e;
  int sx, sy;

  for ( int i = 0; i < world.projectile_pool->count; i++ )
  {
    e = (Entity_t*)d_ArrayGet( world.projectile_pool, i );
    if ( e == NULL ) continue;
    
    if ( e->dead )
    {
      ProjectilePoolRemove( e );
      continue;
    }

    CalculateScreenPos( e->img, e->base, &sx, &sy );

    int facing = 0;

    if ( e->facing == FACING_EAST ||
         e->facing == FACING_NORTH_EAST ||
         e->facing == FACING_NORTH )
    {
      facing = 0;
    }
    
    else if ( e->facing == FACING_NORTH_WEST )
    {
      facing = 2;
    }

    else if ( e->facing == FACING_SOUTH_EAST )
    {
      facing = 3;
    }
    
    else 
    {
      facing = 1;
    }

    
    ISO_AddAnimatedObject( e->body->position, sx+48, sy+48,
                           e->running[facing], LAYER_MID ); //find out why 50
  }
}

