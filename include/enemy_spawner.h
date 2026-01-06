#ifndef __ENEMY_SPAWNER_H__
#define __ENEMY_SPAWNER_H__

#include <Daedalus.h>
#include "structs.h"

EnemySpawner_t* EnemySpawnerInit( dArray_t* enemy_pool, uint32_t spawn_ms );
void EnemySpawnerLogic( EnemySpawner_t* spawner );

#endif

