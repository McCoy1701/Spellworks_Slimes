#include <Archimedes.h>

#include "defines.h"
#include "item_factory.h"
#include "items_init.h"
#include "iso.h"
#include "structs.h"
#include "utils.h"

extern World_t world;

void ItemSystemInit( void )
{
  world.ground_item_pool = d_ArrayInit( MAX_GROUND_ITEMS, sizeof( Item_t ) );
  ItemsLoadTextures();
}

void ItemsDraw( void )
{
  Item_t* item;
  int sx, sy;

  for ( int i = 0; i < world.ground_item_pool->count; i++ )
  {
    item = (Item_t*)d_ArrayGet( world.ground_item_pool, i );
    if ( item == NULL ) continue;
    
    if ( item->picked_up )
    {
      ItemPoolRemove( item );
      continue;
    }

    CalculateScreenPos( item->img, item->base, &sx, &sy );
    ISO_AddStaticObject( item->x, item->z, sx, sy, item->img, LAYER_MID );
  }
}

