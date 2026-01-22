#include <Archimedes.h>

#include "defines.h"
#include "entity_factory.h"
#include "structs.h"
#include "map.h"
#include "utils.h"

extern World_t world;
static const float separation_force_radius = 1.0f; // Distance to avoid other enemies

void SlimesLogic( float dt )
{
  Entity_t* e;

  for ( int i = 0; i < world.entity_pool->count; i++ )
  {
    e = (Entity_t*)d_ArrayGet( world.entity_pool, i );
    if ( e == NULL ) continue;

    if ( e == world.player ||
         strncmp( e->name, "bullet", MAX_NAME_LENGTH ) == 0 ) continue; // if not
    // player and not bullet then it must be a slime
    
    //take the difference between player and enemy, calculate the length of that
    //difference. now the velocity is delta/length * enemy_speed. position +=
    //velocity * dt will move the enemy.
    
    // Calculate separation from nearby enemies (avoid clumping)
    float sep_x = 0.0f;
    float sep_z = 0.0f;

    for ( int j = 0; j < world.entity_pool->count; j++ )
    {
      Entity_t* temp_e = (Entity_t*)d_ArrayGet( world.entity_pool, j );
      if ( temp_e == NULL ) continue;

      if ( i != j && e->state != STATE_IDLE )
      {
        float ex = e->transform->position.x - temp_e->transform->position.x;
        float ez = e->transform->position.z - temp_e->transform->position.z;
        float edist = sqrtf(ex * ex + ez * ez);

        if ( edist < separation_force_radius && edist > 0.1f )
        {
          // Push away from nearby enemies
          float push_strength = ( separation_force_radius - edist ) /
            separation_force_radius;
          sep_x += ( ex / edist ) * push_strength;
          sep_z += ( ez / edist ) * push_strength;
        }
      }
    }
    
    float dx = ( world.player->transform->position.x - 
      e->transform->position.x ) + sep_x;
    
    float dz = ( world.player->transform->position.z -
      e->transform->position.z ) + sep_z;

    float delta_len = d_Sqrtf( dx * dx + dz * dz );
    
    float vx, vz;
    
    if ( delta_len > 0.1f)
    {
      vx = ( dx / delta_len ) * ENEMY_SPEED;
      vz = ( dz / delta_len ) * ENEMY_SPEED;

      e->state = STATE_RUN;
    }
    
    else
    {
      vx = 0;
      vz = 0;

      e->state = STATE_IDLE;
    }

    e->transform->position.x += ( vx * dt );
    e->transform->position.z += ( vz * dt );

  } 
}

void AmethystSlimeInit( int x, int z )
{
  int w = 16;
  int h = 16;
  int frame_count = 2;
  uint32_t frame_duration = 100;
  
  Entity_t* e = EntityInit( "Amethyst_Slime" );

  e->running[0] = a_AnimationCreate( 
    "resources/assets/Enemies/Amethyst_Slime.png",
    w, h, frame_count, frame_duration );
  
  e->transform->position.x = x;
  e->transform->position.z = z;
}

void BlackSlimeInit( int x, int z )
{
  int w = 16;
  int h = 16;
  int frame_count = 2;
  uint32_t frame_duration = 100;
  
  Entity_t* e = EntityInit( "Black_Slime" );

  e->running[0] = a_AnimationCreate( 
    "resources/assets/Enemies/Black_Slime.png",
    w, h, frame_count, frame_duration );
  
  e->transform->position.x = x;
  e->transform->position.z = z;
}

void BlueSlimeInit( int x, int z )
{
  int w = 16;
  int h = 16;
  int frame_count = 2;
  uint32_t frame_duration = 100;
  
  Entity_t* e = EntityInit( "Blue_Slime" );

  e->running[0] = a_AnimationCreate( 
    "resources/assets/Enemies/Blue_Slime.png",
    w, h, frame_count, frame_duration );
  
  e->transform->position.x = x;
  e->transform->position.z = z;
}

void BronzeSlimeInit( int x, int z )
{
  int w = 16;
  int h = 16;
  int frame_count = 2;
  uint32_t frame_duration = 100;
  
  Entity_t* e = EntityInit( "Bronze_Slime" );

  e->running[0] = a_AnimationCreate( 
    "resources/assets/Enemies/Bronze_Slime.png",
    w, h, frame_count, frame_duration );
  
  e->transform->position.x = x;
  e->transform->position.z = z;
}

void ChocolateSlimeInit( int x, int z )
{
  int w = 16;
  int h = 16;
  int frame_count = 2;
  uint32_t frame_duration = 100;
  
  Entity_t* e = EntityInit( "Chocolate_Slime" );

  e->running[0] = a_AnimationCreate( 
    "resources/assets/Enemies/Chocolate_Slime.png",
    w, h, frame_count, frame_duration );
  
  e->transform->position.x = x;
  e->transform->position.z = z;
}

void GoldSlimeInit( int x, int z )
{
  int w = 16;
  int h = 16;
  int frame_count = 2;
  uint32_t frame_duration = 100;
  
  Entity_t* e = EntityInit( "Gold_Slime" );

  e->running[0] = a_AnimationCreate( 
    "resources/assets/Enemies/Gold_Slime.png",
    w, h, frame_count, frame_duration );
  
  e->transform->position.x = x;
  e->transform->position.z = z;
}

void GreenSlimeInit( int x, int z )
{
  int w = 16;
  int h = 16;
  int frame_count = 2;
  uint32_t frame_duration = 100;
  
  Entity_t* e = EntityInit( "Green_Slime" );

  e->running[0] = a_AnimationCreate( 
    "resources/assets/Enemies/Green_Slime.png",
    w, h, frame_count, frame_duration );
  
  e->transform->position.x = x;
  e->transform->position.z = z;
}

void InvertedSlimeInit( int x, int z )
{
  int w = 16;
  int h = 16;
  int frame_count = 2;
  uint32_t frame_duration = 100;
  
  Entity_t* e = EntityInit( "Inverted_Slime" );

  e->running[0] = a_AnimationCreate( 
    "resources/assets/Enemies/Inverted_Slime.png",
    w, h, frame_count, frame_duration );
  
  e->transform->position.x = x;
  e->transform->position.z = z;
}

void MarmaladeSlimeInit( int x, int z )
{
  int w = 16;
  int h = 16;
  int frame_count = 2;
  uint32_t frame_duration = 100;
  
  Entity_t* e = EntityInit( "Marmalade_Slime" );

  e->running[0] = a_AnimationCreate( 
    "resources/assets/Enemies/Marmalade_Slime.png",
    w, h, frame_count, frame_duration );
  
  e->transform->position.x = x;
  e->transform->position.z = z;
}

void MintSlimeInit( int x, int z )
{
  int w = 16;
  int h = 16;
  int frame_count = 2;
  uint32_t frame_duration = 100;
  
  Entity_t* e = EntityInit( "Mint_Slime" );

  e->running[0] = a_AnimationCreate( 
    "resources/assets/Enemies/Mint_Slime.png",
    w, h, frame_count, frame_duration );
  
  e->transform->position.x = x;
  e->transform->position.z = z;
}

void ObsidianSlimeInit( int x, int z )
{
  int w = 16;
  int h = 16;
  int frame_count = 2;
  uint32_t frame_duration = 100;
  
  Entity_t* e = EntityInit( "Obsidian_Slime" );

  e->running[0] = a_AnimationCreate( 
    "resources/assets/Enemies/Obsidian_Slime.png",
    w, h, frame_count, frame_duration );
  
  e->transform->position.x = x;
  e->transform->position.z = z;
}

void PollutedSlimeInit( int x, int z )
{
  int w = 16;
  int h = 16;
  int frame_count = 2;
  uint32_t frame_duration = 100;
  
  Entity_t* e = EntityInit( "Polluted_Slime" );

  e->running[0] = a_AnimationCreate( 
    "resources/assets/Enemies/Polluted_Slime.png",
    w, h, frame_count, frame_duration );
  
  e->transform->position.x = x;
  e->transform->position.z = z;
}

void PrimordialSlimeInit( int x, int z )
{
  int w = 16;
  int h = 16;
  int frame_count = 2;
  uint32_t frame_duration = 100;
  
  Entity_t* e = EntityInit( "Primordial_Slime" );

  e->running[0] = a_AnimationCreate( 
    "resources/assets/Enemies/Primordial_Slime.png",
    w, h, frame_count, frame_duration );
  
  e->transform->position.x = x;
  e->transform->position.z = z;
}

void PurpleSlimeInit( int x, int z )
{
  int w = 16;
  int h = 16;
  int frame_count = 2;
  uint32_t frame_duration = 100;
  
  Entity_t* e = EntityInit( "Purple_Slime" );

  e->running[0] = a_AnimationCreate( 
    "resources/assets/Enemies/Purple_Slime.png",
    w, h, frame_count, frame_duration );
  
  e->transform->position.x = x;
  e->transform->position.z = z;
}

void RadioactiveSlimeInit( int x, int z )
{
  int w = 16;
  int h = 16;
  int frame_count = 2;
  uint32_t frame_duration = 100;
  
  Entity_t* e = EntityInit( "Radioactive_Slime" );

  e->running[0] = a_AnimationCreate( 
    "resources/assets/Enemies/Radioactive_Slime.png",
    w, h, frame_count, frame_duration );
  
  e->transform->position.x = x;
  e->transform->position.z = z;
}

void RedSlimeInit( int x, int z )
{
  int w = 16;
  int h = 16;
  int frame_count = 2;
  uint32_t frame_duration = 100;
  
  Entity_t* e = EntityInit( "Red_Slime" );

  e->running[0] = a_AnimationCreate( 
    "resources/assets/Enemies/Red_Slime.png",
    w, h, frame_count, frame_duration );
  
  e->transform->position.x = x;
  e->transform->position.z = z;
}

void SandstoneSlimeInit( int x, int z )
{
  int w = 16;
  int h = 16;
  int frame_count = 2;
  uint32_t frame_duration = 100;
  
  Entity_t* e = EntityInit( "Sandstone_Slime" );

  e->running[0] = a_AnimationCreate( 
    "resources/assets/Enemies/SandStone_Slime.png",
    w, h, frame_count, frame_duration );
  
  e->transform->position.x = x;
  e->transform->position.z = z;
}

void StoneSlimeInit( int x, int z )
{
  int w = 16;
  int h = 16;
  int frame_count = 2;
  uint32_t frame_duration = 100;
  
  Entity_t* e = EntityInit( "Stone_Slime" );

  e->running[0] = a_AnimationCreate( 
    "resources/assets/Enemies/Stone_Slime.png",
    w, h, frame_count, frame_duration );
  
  e->transform->position.x = x;
  e->transform->position.z = z;
}

void WaterSlimeInit( int x, int z )
{
  int w = 16;
  int h = 16;
  int frame_count = 2;
  uint32_t frame_duration = 100;
  
  Entity_t* e = EntityInit( "Water_Slime" );

  e->running[0] = a_AnimationCreate( 
    "resources/assets/Enemies/Water_Slime.png",
    w, h, frame_count, frame_duration );
  
  e->transform->position.x = x;
  e->transform->position.z = z;
}

void WhiteSlimeInit( int x, int z )
{
  int w = 16;
  int h = 16;
  int frame_count = 2;
  uint32_t frame_duration = 100;
  
  Entity_t* e = EntityInit( "White_Slime" );

  e->running[0] = a_AnimationCreate( 
    "resources/assets/Enemies/White_Slime.png",
    w, h, frame_count, frame_duration );
  
  e->transform->position.x = x;
  e->transform->position.z = z;
}

