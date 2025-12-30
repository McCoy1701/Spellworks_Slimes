
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

}

void BlueSlimeInit( int x, int z )
{

}

void BronzeSlimeInit( int x, int z )
{

}

void ChocolateSlimeInit( int x, int z )
{

}

void GoldSlimeInit( int x, int z )
{

}

void GreenSlimeInit( int x, int z )
{

}

void InvertedSlimeInit( int x, int z )
{

}

void MarmaladeSlimeInit( int x, int z )
{

}

void MintSlimeInit( int x, int z )
{

}

void ObsidianSlimeInit( int x, int z )
{

}

void PollutedSlimeInit( int x, int z )
{

}

void PrimordialSlimeInit( int x, int z )
{

}

void PurpleSlimeInit( int x, int z )
{

}

void RadioactiveSlimeInit( int x, int z )
{

}

void RedSlimeInit( int x, int z )
{
  
}

void SandstoneSlimeInit( int x, int z )
{

}

void StoneSlimeInit( int x, int z )
{

}

void WaterSlimeInit( int x, int z )
{

}

void WhiteSlimeInit( int x, int z )
{

}

void SlimeLogic( float dt )
{

}

