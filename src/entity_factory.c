#include <Archimedes.h>
#include <Daedalus.h>

#include "defines.h"
#include "structs.h"
#include "entity_factory.h"

#include "entities/player_entity.h"
#include "entities/bullet_entity.h"
#include "entities/base_enemy_entity.h"

extern World_t world;

static Entity_t* SpawnEntity( void );
static Entity_Init_Func_t* GetInitFunc( const char* name );
static void AddInitFunc(const char* name, void (*init)( Entity_t* e ) );

static Entity_Init_Func_t head, *tail;

void EntityFactoryInit( void )
{
  memset( &head, 0, sizeof( Entity_Init_Func_t ) );
  tail = &head;

  AddInitFunc( "player_entity", PlayerEntityInit );
  AddInitFunc( "bullet_entity", BulletEntityInit );
  AddInitFunc( "base_enemy_entity", BaseEnemyEntityInit );
}

Entity_t* EntityInit( const char* name )
{
  Entity_t* e = SpawnEntity();

  GetInitFunc( name )->init(e);

  e->id = world.stats.tl_entities;
  
  d_ArrayAppend( world.entity_pool, e );
  world.stats.tl_entities++;

  return e;
}

Entity_t* ProjectileInit( const char* name )
{
  Entity_t* e = SpawnEntity();

  GetInitFunc( name )->init(e);

  e->id = world.stats.tl_projectiles;
  
  d_ArrayAppend( world.projectile_pool, e );
  world.stats.tl_projectiles++;

  return e;
}

void EntityPoolRemove( Entity_t* e )
{
  d_ArrayRemoveByReference( world.entity_pool, e );

  EntityDestroy( e );
}

void ProjectilePoolRemove( Entity_t* e )
{
  d_ArrayRemoveByReference( world.projectile_pool, e );

  EntityDestroy( e );
}

void EntityDestroy( Entity_t* e )
{
  if ( e == NULL ) return;

  if ( e->img )
  {
    a_ImageFree( e->img );
    e->img = NULL;
  }

  if ( e->running[0] != NULL && e->idle[0] != NULL )
  {
    for ( int i = 0; i < FACING_MAX; i++ )
    {
      a_AnimationFree( e->running[i] );
      a_AnimationFree( e->idle[i] );
      e->running[i] = e->idle[i] = NULL;
    }
  }
  e = NULL;
}

static Entity_t* SpawnEntity( void )
{
  if ( world.entity_pool->count < MAX_ENTITIES )
  {
    Entity_t* e = malloc( sizeof( Entity_t ) );
    memset( e, 0, sizeof( Entity_t ) );

    return e;
  }

  LOG("TOO MANY ENTITIES!");
  return NULL;
}

static Entity_Init_Func_t* GetInitFunc( const char* name )
{
  Entity_Init_Func_t* init_func;
  for ( init_func = head.next; init_func != NULL; init_func = init_func->next )
  {
    if ( strcmp( init_func->name, name ) == 0 )
    {
      return init_func;

    }
  }

  char log_msg[MAX_NAME_LENGTH];
  snprintf( log_msg, MAX_NAME_LENGTH, "Uknown Entity: %s", name );
  LOG( log_msg );

  return NULL;
}

static void AddInitFunc(const char* name, void (*init)( Entity_t* e ) )
{
  Entity_Init_Func_t* init_func = malloc( sizeof( Entity_Init_Func_t ) );
  memset( init_func, 0, sizeof( Entity_Init_Func_t ) );

  tail->next = init_func;
  tail = init_func;

  STRNCPY( init_func->name, name, MAX_NAME_LENGTH );
  init_func->init = init;
}

