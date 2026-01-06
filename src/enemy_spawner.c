#include "enemy_spawner.h"
#include <Archimedes.h>

#include "defines.h"
#include "entity_factory.h"
#include "iso.h"
#include "map.h"
#include "structs.h"
#include "utils.h"

extern World_t world;

EnemySpawner_t* EnemySpawnerInit( dArray_t* enemy_pool, uint32_t spawn_ms )
{
  EnemySpawner_t* new_spawner = malloc( sizeof( EnemySpawner_t ) );
  if ( new_spawner == NULL ) return NULL;

  new_spawner->enemy_pool = enemy_pool;
  new_spawner->timer = a_TimerCreate();
  new_spawner->wait_ms = spawn_ms;

  return new_spawner;
}

void EnemySpawnerLogic( EnemySpawner_t* spawner )
{
  if ( a_TimerOneshot( spawner->timer, spawner->wait_ms ) )
  {
    int rnd_enemy = rand() % spawner->enemy_pool->count;
    char* enemy_name = (char*)d_ArrayGet( spawner->enemy_pool, rnd_enemy );
    printf( "%s, %d\n", enemy_name, rnd_enemy );
    EntityInit( enemy_name );
  }
}

