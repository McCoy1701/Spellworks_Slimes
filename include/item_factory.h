#ifndef __ITEM_FACTORY_H__
#define __ITEM_FACTORY_H__

#include "structs.h"

void ItemFactoryInit( void );
Item_t* ItemInit( const char* name );

void ItemPoolRemove( Item_t* e );
void ItemDestroy( Item_t* e );

#endif

