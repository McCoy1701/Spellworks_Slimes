#ifndef __ENTITY_FACTORY_H__
#define __ENTITY_FACTORY_H__

#include "defines.h"
#include "structs.h"

void EntityFactoryInit( void );
Entity_t* EntityInit( const char* name );

void EntityDestroy( Entity_t* e );

#endif

