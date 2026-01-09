#include "enemy_spawner.h"
#include <Archimedes.h>

#include "defines.h"
#include "entity_logic/slimes.h"
#include "entity_factory.h"
#include "iso.h"
#include "map.h"
#include "structs.h"
#include "utils.h"

extern World_t world;

static void load_dir_pools( void );

dVec2_t north_dir_pool[4];
dVec2_t south_dir_pool[4];
dVec2_t east_dir_pool[4];
dVec2_t west_dir_pool[4];

EnemySpawner_t* EnemySpawnerInit( dArray_t* enemy_pool, uint32_t spawn_ms )
{
  EnemySpawner_t* new_spawner = malloc( sizeof( EnemySpawner_t ) );
  if ( new_spawner == NULL ) return NULL;

  new_spawner->enemy_pool = enemy_pool;
  new_spawner->timer = a_TimerCreate();
  new_spawner->wait_ms = spawn_ms;
  
  load_dir_pools();

  return new_spawner;
}

void EnemySpawnerLogic( EnemySpawner_t* spawner )
{
  if ( a_TimerOneshot( spawner->timer, spawner->wait_ms ) )
  {
    int rnd_enemy = rand() % spawner->enemy_pool->count;
    int* enemy_id = (int*)d_ArrayGet( spawner->enemy_pool, rnd_enemy );

    int rnd_dir = rand() % DIRECTION_MAX;
    int rnd_spot = rand() % DIRECTION_MAX;
    dVec2_t spawn_pos = {0};

    switch ( rnd_dir )
    {
      case NORTH:
        spawn_pos = north_dir_pool[rnd_spot];
        break;
      
      case SOUTH:
        spawn_pos = south_dir_pool[rnd_spot];
        break;
      
      case EAST:
        spawn_pos = east_dir_pool[rnd_spot];
        break;
      
      case WEST:
        spawn_pos = west_dir_pool[rnd_spot];
        break;
      
      default:
        break;
    }

    switch ( *enemy_id )
    {
      case SLIME_AMETHYST:
        AmethystSlimeInit( spawn_pos.x, spawn_pos.y );
        break;
      
      case SLIME_BLACK:
        BlackSlimeInit( spawn_pos.x, spawn_pos.y );
        break;
      
      case SLIME_BLUE:
        BlueSlimeInit( spawn_pos.x, spawn_pos.y );
        break;
      
      case SLIME_BRONZE:
        BronzeSlimeInit( spawn_pos.x, spawn_pos.y );
        break;
      
      case SLIME_CHOCOLATE:
        ChocolateSlimeInit( spawn_pos.x, spawn_pos.y );
        break;
      
      case SLIME_GOLD:
        GoldSlimeInit( spawn_pos.x, spawn_pos.y );
        break;
      
      case SLIME_GREEN:
        GreenSlimeInit( spawn_pos.x, spawn_pos.y );
        break;
      
      case SLIME_INVERTED:
        InvertedSlimeInit( spawn_pos.x, spawn_pos.y );
        break;
      
      case SLIME_MARMALADE:
        MarmaladeSlimeInit( spawn_pos.x, spawn_pos.y );
        break;
      
      case SLIME_MINT:
        MintSlimeInit( spawn_pos.x, spawn_pos.y );
        break;
      
      case SLIME_OBSIDIAN:
        ObsidianSlimeInit( spawn_pos.x, spawn_pos.y );
        break;
      
      case SLIME_POLLUTED:
        PollutedSlimeInit( spawn_pos.x, spawn_pos.y );
        break;
      
      case SLIME_PRIMORDIAL:
        PrimordialSlimeInit( spawn_pos.x, spawn_pos.y );
        break;
      
      case SLIME_PURPLE:
        PurpleSlimeInit( spawn_pos.x, spawn_pos.y );
        break;
      
      case SLIME_RADIOACTIVE:
        RadioactiveSlimeInit( spawn_pos.x, spawn_pos.y );
        break;
      
      case SLIME_RED:
        RedSlimeInit( spawn_pos.x, spawn_pos.y );
        break;
      
      case SLIME_SANDSTONE:
        SandstoneSlimeInit( spawn_pos.x, spawn_pos.y );
        break;
      
      case SLIME_STONE:
        StoneSlimeInit( spawn_pos.x, spawn_pos.y );
        break;
      
      case SLIME_WATER:
        WaterSlimeInit( spawn_pos.x, spawn_pos.y );
        break;
      
      case SLIME_WHITE:
        WhiteSlimeInit( spawn_pos.x, spawn_pos.y );
        break;

      default:
        break;
    }
  }
}

static void load_dir_pools( void )
{
  int half = MAP_SIZE / 2;
  int map_min = 0;
  int map_max = MAP_SIZE-1;

  dVec2_t n0, n1, n2, n3;
  n0 = (dVec2_t){ .x = map_max, .y = half-1 };
  n1 = (dVec2_t){ .x = map_max, .y = half };
  n2 = (dVec2_t){ .x = map_max, .y = half+1 };
  n3 = (dVec2_t){ .x = map_max, .y = half+2 };
  north_dir_pool[0] = n0; 
  north_dir_pool[1] = n1; 
  north_dir_pool[2] = n2; 
  north_dir_pool[3] = n3; 
  
  dVec2_t s0, s1, s2, s3;
  s0 = (dVec2_t){ .x = map_min, .y = half-1 };
  s1 = (dVec2_t){ .x = map_min, .y = half };
  s2 = (dVec2_t){ .x = map_min, .y = half+1 };
  s3 = (dVec2_t){ .x = map_min, .y = half+2 };
  south_dir_pool[0] = s0; 
  south_dir_pool[1] = s1; 
  south_dir_pool[2] = s2; 
  south_dir_pool[3] = s3; 
  
  dVec2_t e0, e1, e2, e3;
  e0 = (dVec2_t){ .x = half-1, .y = map_max };
  e1 = (dVec2_t){ .x = half,   .y = map_max };
  e2 = (dVec2_t){ .x = half+1, .y = map_max };
  e3 = (dVec2_t){ .x = half+2, .y = map_max };
  east_dir_pool[0] = e0; 
  east_dir_pool[1] = e1; 
  east_dir_pool[2] = e2; 
  east_dir_pool[3] = e3; 
  
  dVec2_t w0, w1, w2, w3;
  w0 = (dVec2_t){ .x = half-1, .y = map_min };
  w1 = (dVec2_t){ .x = half,   .y = map_min };
  w2 = (dVec2_t){ .x = half+1, .y = map_min };
  w3 = (dVec2_t){ .x = half+2, .y = map_min };
  west_dir_pool[0] = w0; 
  west_dir_pool[1] = w1; 
  west_dir_pool[2] = w2; 
  west_dir_pool[3] = w3; 
}

