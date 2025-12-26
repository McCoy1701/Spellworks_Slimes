#ifndef __ENTITY_FACTORY_H__
#define __ENTITY_FACTORY_H__

#include "defines.h"
#include "structs.h"

void EntityFactoryInit( void );
Entity_t* EntityInit( const char* name );
Entity_t* ProjectileInit( const char* name );

void EntityPoolRemove( Entity_t* e );
void ProjectilePoolRemove( Entity_t* e );
void EntityDestroy( Entity_t* e );

#endif

