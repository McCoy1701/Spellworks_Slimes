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

    CalculateScreenPos( e, &sx, &sy );
    ISO_AddStaticObject( e->x, e->z, sx, sy, e->img, LAYER_MID );
  }
}

