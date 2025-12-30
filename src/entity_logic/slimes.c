
#include <Archimedes.h>

#include "defines.h"
#include "entity_factory.h"
#include "structs.h"
#include "utils.h"

extern World_t world;

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
  
  e->x = x;
  e->z = z;
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
  
  e->x = x;
  e->z = z;
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
  
  e->x = x;
  e->z = z;
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
  
  e->x = x;
  e->z = z;
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
  
  e->x = x;
  e->z = z;
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
  
  e->x = x;
  e->z = z;
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
  
  e->x = x;
  e->z = z;
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
  
  e->x = x;
  e->z = z;
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
  
  e->x = x;
  e->z = z;
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
  
  e->x = x;
  e->z = z;
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
  
  e->x = x;
  e->z = z;
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
  
  e->x = x;
  e->z = z;
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
  
  e->x = x;
  e->z = z;
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
  
  e->x = x;
  e->z = z;
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
  
  e->x = x;
  e->z = z;
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
  
  e->x = x;
  e->z = z;
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
  
  e->x = x;
  e->z = z;
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
  
  e->x = x;
  e->z = z;
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
  
  e->x = x;
  e->z = z;
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
  
  e->x = x;
  e->z = z;
}

void SlimeLogic( float dt )
{

}

