#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "structs.h"

void EntitiesInit( void );
void EntitiesDraw( void );

Entity_t* EntitiesAt( int x, int z );

#endif

