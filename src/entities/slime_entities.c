#include <Archimedes.h>

#include "structs.h"

extern World_t world;

void AmethystSlimeEntityInit( Entity_t* e )
{
  e->img = a_ImageLoad( "resources/assets/Enemies/Amethyst_Slime.png" );
  e->base = 10;
  
  dVec3_t gravity  = {0};
  dVec3_t velocity = {0};
  dVec3_t force    = {0};

  float   mass          = 10.0f;
  float   max_speed     = 8.0f;
  float   max_force     = 0.2f;
  uint8_t takes_gravity = 1;

  float   static_friction = 0.0f;
  float   dynamic_friction = 0.0f;
  float   restitution = 0.0f;

  e->body = d_KinematicBodyCreate( gravity, velocity,
                                   force, mass,
                                   max_speed, max_force,
                                   takes_gravity, 
                                   static_friction,
                                   dynamic_friction,
                                   restitution );
  
  dVec3_t position = {0};
  dVec3_t scale    = {0};
  double  rotation = 0.0f;
  e->transform = d_TransformCreate( position, scale, rotation );
  
  STRNCPY( e->name, "Amethyst_Slime", MAX_NAME_LENGTH );
}

void BlackSlimeEntityInit( Entity_t* e )
{
  e->img = a_ImageLoad( "resources/assets/Enemies/Black_Slime.png" );
  e->base = 10;
  
  dVec3_t gravity  = {0};
  dVec3_t velocity = {0};
  dVec3_t force    = {0};

  float   mass          = 10.0f;
  float   max_speed     = 8.0f;
  float   max_force     = 0.2f;
  uint8_t takes_gravity = 1;

  float   static_friction = 0.0f;
  float   dynamic_friction = 0.0f;
  float   restitution = 0.0f;

  e->body = d_KinematicBodyCreate( gravity, velocity,
                                   force, mass,
                                   max_speed, max_force,
                                   takes_gravity, 
                                   static_friction,
                                   dynamic_friction,
                                   restitution );
 
  dVec3_t position = {0};
  dVec3_t scale    = {0};
  double  rotation = 0.0f;
  e->transform = d_TransformCreate( position, scale, rotation );
  
  STRNCPY( e->name, "Black_Slime", MAX_NAME_LENGTH );
}

void BlueSlimeEntityInit( Entity_t* e )
{
  e->img = a_ImageLoad( "resources/assets/Enemies/Blue_Slime.png" );
  e->base = 10;
  
  dVec3_t gravity  = {0};
  dVec3_t velocity = {0};
  dVec3_t force    = {0};

  float   mass          = 10.0f;
  float   max_speed     = 8.0f;
  float   max_force     = 0.2f;
  uint8_t takes_gravity = 1;

  float   static_friction = 0.0f;
  float   dynamic_friction = 0.0f;
  float   restitution = 0.0f;

  e->body = d_KinematicBodyCreate( gravity, velocity,
                                   force, mass,
                                   max_speed, max_force,
                                   takes_gravity, 
                                   static_friction,
                                   dynamic_friction,
                                   restitution );
 
  dVec3_t position = {0};
  dVec3_t scale    = {0};
  double  rotation = 0.0f;
  e->transform = d_TransformCreate( position, scale, rotation );
  
  STRNCPY( e->name, "Blue_Slime", MAX_NAME_LENGTH );
}

void BronzeSlimeEntityInit( Entity_t* e )
{
  e->img = a_ImageLoad( "resources/assets/Enemies/Bronze_Slime.png" );
  e->base = 10;
  
  dVec3_t gravity  = {0};
  dVec3_t velocity = {0};
  dVec3_t force    = {0};

  float   mass          = 10.0f;
  float   max_speed     = 8.0f;
  float   max_force     = 0.2f;
  uint8_t takes_gravity = 1;

  float   static_friction = 0.0f;
  float   dynamic_friction = 0.0f;
  float   restitution = 0.0f;

  e->body = d_KinematicBodyCreate( gravity, velocity,
                                   force, mass,
                                   max_speed, max_force,
                                   takes_gravity, 
                                   static_friction,
                                   dynamic_friction,
                                   restitution );
 
  dVec3_t position = {0};
  dVec3_t scale    = {0};
  double  rotation = 0.0f;
  e->transform = d_TransformCreate( position, scale, rotation );
  
  STRNCPY( e->name, "Bronze_Slime", MAX_NAME_LENGTH );
}

void ChocolateSlimeEntityInit( Entity_t* e )
{
  e->img = a_ImageLoad( "resources/assets/Enemies/Chocolate_Slime.png" );
  e->base = 10;
  
  dVec3_t gravity  = {0};
  dVec3_t velocity = {0};
  dVec3_t force    = {0};

  float   mass          = 10.0f;
  float   max_speed     = 8.0f;
  float   max_force     = 0.2f;
  uint8_t takes_gravity = 1;

  float   static_friction = 0.0f;
  float   dynamic_friction = 0.0f;
  float   restitution = 0.0f;

  e->body = d_KinematicBodyCreate( gravity, velocity,
                                   force, mass,
                                   max_speed, max_force,
                                   takes_gravity, 
                                   static_friction,
                                   dynamic_friction,
                                   restitution );
 
  dVec3_t position = {0};
  dVec3_t scale    = {0};
  double  rotation = 0.0f;
  e->transform = d_TransformCreate( position, scale, rotation );
  
  STRNCPY( e->name, "Chocolate_Slime", MAX_NAME_LENGTH );
}

void GoldSlimeEntityInit( Entity_t* e )
{
  e->img = a_ImageLoad( "resources/assets/Enemies/Gold_Slime.png" );
  e->base = 10;
  
  dVec3_t gravity  = {0};
  dVec3_t velocity = {0};
  dVec3_t force    = {0};

  float   mass          = 10.0f;
  float   max_speed     = 8.0f;
  float   max_force     = 0.2f;
  uint8_t takes_gravity = 1;

  float   static_friction = 0.0f;
  float   dynamic_friction = 0.0f;
  float   restitution = 0.0f;

  e->body = d_KinematicBodyCreate( gravity, velocity,
                                   force, mass,
                                   max_speed, max_force,
                                   takes_gravity, 
                                   static_friction,
                                   dynamic_friction,
                                   restitution );
  
  dVec3_t position = {0};
  dVec3_t scale    = {0};
  double  rotation = 0.0f;
  e->transform = d_TransformCreate( position, scale, rotation );
  
  STRNCPY( e->name, "Gold_Slime", MAX_NAME_LENGTH );
}

void GreenSlimeEntityInit( Entity_t* e )
{
  e->img = a_ImageLoad( "resources/assets/Enemies/Green_Slime.png" );
  e->base = 10;
  
  dVec3_t gravity  = {0};
  dVec3_t velocity = {0};
  dVec3_t force    = {0};

  float   mass          = 10.0f;
  float   max_speed     = 8.0f;
  float   max_force     = 0.2f;
  uint8_t takes_gravity = 1;

  float   static_friction = 0.0f;
  float   dynamic_friction = 0.0f;
  float   restitution = 0.0f;

  e->body = d_KinematicBodyCreate( gravity, velocity,
                                   force, mass,
                                   max_speed, max_force,
                                   takes_gravity, 
                                   static_friction,
                                   dynamic_friction,
                                   restitution );
 
  dVec3_t position = {0};
  dVec3_t scale    = {0};
  double  rotation = 0.0f;
  e->transform = d_TransformCreate( position, scale, rotation );
  
  STRNCPY( e->name, "Green_Slime", MAX_NAME_LENGTH );
}

void InvertedSlimeEntityInit( Entity_t* e )
{
  e->img = a_ImageLoad( "resources/assets/Enemies/Inverted_Slime.png" );
  e->base = 10;
  
  dVec3_t gravity  = {0};
  dVec3_t velocity = {0};
  dVec3_t force    = {0};

  float   mass          = 10.0f;
  float   max_speed     = 8.0f;
  float   max_force     = 0.2f;
  uint8_t takes_gravity = 1;

  float   static_friction = 0.0f;
  float   dynamic_friction = 0.0f;
  float   restitution = 0.0f;

  e->body = d_KinematicBodyCreate( gravity, velocity,
                                   force, mass,
                                   max_speed, max_force,
                                   takes_gravity, 
                                   static_friction,
                                   dynamic_friction,
                                   restitution );
 
  dVec3_t position = {0};
  dVec3_t scale    = {0};
  double  rotation = 0.0f;
  e->transform = d_TransformCreate( position, scale, rotation );
  
  STRNCPY( e->name, "Inverted_Slime", MAX_NAME_LENGTH );
}

void MarmaladeSlimeEntityInit( Entity_t* e )
{
  e->img = a_ImageLoad( "resources/assets/Enemies/Marmalade_Slime.png" );
  e->base = 10;
  
  dVec3_t gravity  = {0};
  dVec3_t velocity = {0};
  dVec3_t force    = {0};

  float   mass          = 10.0f;
  float   max_speed     = 8.0f;
  float   max_force     = 0.2f;
  uint8_t takes_gravity = 1;

  float   static_friction = 0.0f;
  float   dynamic_friction = 0.0f;
  float   restitution = 0.0f;

  e->body = d_KinematicBodyCreate( gravity, velocity,
                                   force, mass,
                                   max_speed, max_force,
                                   takes_gravity, 
                                   static_friction,
                                   dynamic_friction,
                                   restitution );
 
  dVec3_t position = {0};
  dVec3_t scale    = {0};
  double  rotation = 0.0f;
  e->transform = d_TransformCreate( position, scale, rotation );
  
  STRNCPY( e->name, "Marmalade_Slime", MAX_NAME_LENGTH );
}

void MintSlimeEntityInit( Entity_t* e )
{
  e->img = a_ImageLoad( "resources/assets/Enemies/Mint_Slime.png" );
  e->base = 10;
  
  dVec3_t gravity  = {0};
  dVec3_t velocity = {0};
  dVec3_t force    = {0};

  float   mass          = 10.0f;
  float   max_speed     = 8.0f;
  float   max_force     = 0.2f;
  uint8_t takes_gravity = 1;

  float   static_friction = 0.0f;
  float   dynamic_friction = 0.0f;
  float   restitution = 0.0f;

  e->body = d_KinematicBodyCreate( gravity, velocity,
                                   force, mass,
                                   max_speed, max_force,
                                   takes_gravity, 
                                   static_friction,
                                   dynamic_friction,
                                   restitution );
 
  dVec3_t position = {0};
  dVec3_t scale    = {0};
  double  rotation = 0.0f;
  e->transform = d_TransformCreate( position, scale, rotation );
  
  STRNCPY( e->name, "Mint_Slime", MAX_NAME_LENGTH );
}

void ObsidianSlimeEntityInit( Entity_t* e )
{
  e->img = a_ImageLoad( "resources/assets/Enemies/Obsidian_Slime.png" );
  e->base = 10;
  
  dVec3_t gravity  = {0};
  dVec3_t velocity = {0};
  dVec3_t force    = {0};

  float   mass          = 10.0f;
  float   max_speed     = 8.0f;
  float   max_force     = 0.2f;
  uint8_t takes_gravity = 1;

  float   static_friction = 0.0f;
  float   dynamic_friction = 0.0f;
  float   restitution = 0.0f;

  e->body = d_KinematicBodyCreate( gravity, velocity,
                                   force, mass,
                                   max_speed, max_force,
                                   takes_gravity, 
                                   static_friction,
                                   dynamic_friction,
                                   restitution );
 
  dVec3_t position = {0};
  dVec3_t scale    = {0};
  double  rotation = 0.0f;
  e->transform = d_TransformCreate( position, scale, rotation );
  
  STRNCPY( e->name, "Obsidian_Slime", MAX_NAME_LENGTH );
}

void PollutedSlimeEntityInit( Entity_t* e )
{
  e->img = a_ImageLoad( "resources/assets/Enemies/Polluted_Slime.png" );
  e->base = 10;
  
  dVec3_t gravity  = {0};
  dVec3_t velocity = {0};
  dVec3_t force    = {0};

  float   mass          = 10.0f;
  float   max_speed     = 8.0f;
  float   max_force     = 0.2f;
  uint8_t takes_gravity = 1;

  float   static_friction = 0.0f;
  float   dynamic_friction = 0.0f;
  float   restitution = 0.0f;

  e->body = d_KinematicBodyCreate( gravity, velocity,
                                   force, mass,
                                   max_speed, max_force,
                                   takes_gravity, 
                                   static_friction,
                                   dynamic_friction,
                                   restitution );
 
  dVec3_t position = {0};
  dVec3_t scale    = {0};
  double  rotation = 0.0f;
  e->transform = d_TransformCreate( position, scale, rotation );
  
  STRNCPY( e->name, "Polluted_Slime", MAX_NAME_LENGTH );
}

void PrimordialSlimeEntityInit( Entity_t* e )
{
  e->img = a_ImageLoad( "resources/assets/Enemies/Primodial_Slime.png" );
  e->base = 10;
  
  dVec3_t gravity  = {0};
  dVec3_t velocity = {0};
  dVec3_t force    = {0};

  float   mass          = 10.0f;
  float   max_speed     = 8.0f;
  float   max_force     = 0.2f;
  uint8_t takes_gravity = 1;

  float   static_friction = 0.0f;
  float   dynamic_friction = 0.0f;
  float   restitution = 0.0f;

  e->body = d_KinematicBodyCreate( gravity, velocity,
                                   force, mass,
                                   max_speed, max_force,
                                   takes_gravity, 
                                   static_friction,
                                   dynamic_friction,
                                   restitution );
 
  dVec3_t position = {0};
  dVec3_t scale    = {0};
  double  rotation = 0.0f;
  e->transform = d_TransformCreate( position, scale, rotation );
  
  STRNCPY( e->name, "Primodial_Slime", MAX_NAME_LENGTH );
}

void PurpleSlimeEntityInit( Entity_t* e )
{
  e->img = a_ImageLoad( "resources/assets/Enemies/Purple_Slime.png" );
  e->base = 10;
  
  dVec3_t gravity  = {0};
  dVec3_t velocity = {0};
  dVec3_t force    = {0};

  float   mass          = 10.0f;
  float   max_speed     = 8.0f;
  float   max_force     = 0.2f;
  uint8_t takes_gravity = 1;

  float   static_friction = 0.0f;
  float   dynamic_friction = 0.0f;
  float   restitution = 0.0f;

  e->body = d_KinematicBodyCreate( gravity, velocity,
                                   force, mass,
                                   max_speed, max_force,
                                   takes_gravity, 
                                   static_friction,
                                   dynamic_friction,
                                   restitution );
 
  dVec3_t position = {0};
  dVec3_t scale    = {0};
  double  rotation = 0.0f;
  e->transform = d_TransformCreate( position, scale, rotation );
  
  STRNCPY( e->name, "Purple_Slime", MAX_NAME_LENGTH );
}

void RadioactiveSlimeEntityInit( Entity_t* e )
{
  e->img = a_ImageLoad( "resources/assets/Enemies/Radioactive_Slime.png" );
  e->base = 10;
  
  dVec3_t gravity  = {0};
  dVec3_t velocity = {0};
  dVec3_t force    = {0};

  float   mass          = 10.0f;
  float   max_speed     = 8.0f;
  float   max_force     = 0.2f;
  uint8_t takes_gravity = 1;

  float   static_friction = 0.0f;
  float   dynamic_friction = 0.0f;
  float   restitution = 0.0f;

  e->body = d_KinematicBodyCreate( gravity, velocity,
                                   force, mass,
                                   max_speed, max_force,
                                   takes_gravity, 
                                   static_friction,
                                   dynamic_friction,
                                   restitution );
 
  dVec3_t position = {0};
  dVec3_t scale    = {0};
  double  rotation = 0.0f;
  e->transform = d_TransformCreate( position, scale, rotation );
  
  STRNCPY( e->name, "Radioactive_Slime", MAX_NAME_LENGTH );
}

void RedSlimeEntityInit( Entity_t* e )
{
  e->img = a_ImageLoad( "resources/assets/Enemies/Red_Slime.png" );
  e->base = 10;
  
  dVec3_t gravity  = {0};
  dVec3_t velocity = {0};
  dVec3_t force    = {0};

  float   mass          = 10.0f;
  float   max_speed     = 8.0f;
  float   max_force     = 0.2f;
  uint8_t takes_gravity = 1;

  float   static_friction = 0.0f;
  float   dynamic_friction = 0.0f;
  float   restitution = 0.0f;

  e->body = d_KinematicBodyCreate( gravity, velocity,
                                   force, mass,
                                   max_speed, max_force,
                                   takes_gravity, 
                                   static_friction,
                                   dynamic_friction,
                                   restitution );
 
  dVec3_t position = {0};
  dVec3_t scale    = {0};
  double  rotation = 0.0f;
  e->transform = d_TransformCreate( position, scale, rotation );
  
  STRNCPY( e->name, "Red_Slime", MAX_NAME_LENGTH );
}

void SandstoneSlimeEntityInit( Entity_t* e )
{
  e->img = a_ImageLoad( "resources/assets/Enemies/SandStone_Slime.png" );
  e->base = 10;
  
  dVec3_t gravity  = {0};
  dVec3_t velocity = {0};
  dVec3_t force    = {0};

  float   mass          = 10.0f;
  float   max_speed     = 8.0f;
  float   max_force     = 0.2f;
  uint8_t takes_gravity = 1;

  float   static_friction = 0.0f;
  float   dynamic_friction = 0.0f;
  float   restitution = 0.0f;

  e->body = d_KinematicBodyCreate( gravity, velocity,
                                   force, mass,
                                   max_speed, max_force,
                                   takes_gravity, 
                                   static_friction,
                                   dynamic_friction,
                                   restitution );
 
  dVec3_t position = {0};
  dVec3_t scale    = {0};
  double  rotation = 0.0f;
  e->transform = d_TransformCreate( position, scale, rotation );
  
  STRNCPY( e->name, "Sandstone_Slime", MAX_NAME_LENGTH );
}

void StoneSlimeEntityInit( Entity_t* e )
{
  e->img = a_ImageLoad( "resources/assets/Enemies/Stone_Slime.png" );
  e->base = 10;
  
  dVec3_t gravity  = {0};
  dVec3_t velocity = {0};
  dVec3_t force    = {0};

  float   mass          = 10.0f;
  float   max_speed     = 8.0f;
  float   max_force     = 0.2f;
  uint8_t takes_gravity = 1;

  float   static_friction = 0.0f;
  float   dynamic_friction = 0.0f;
  float   restitution = 0.0f;

  e->body = d_KinematicBodyCreate( gravity, velocity,
                                   force, mass,
                                   max_speed, max_force,
                                   takes_gravity, 
                                   static_friction,
                                   dynamic_friction,
                                   restitution );
 
  dVec3_t position = {0};
  dVec3_t scale    = {0};
  double  rotation = 0.0f;
  e->transform = d_TransformCreate( position, scale, rotation );
  
  STRNCPY( e->name, "Stone_Slime", MAX_NAME_LENGTH );
}

void WaterSlimeEntityInit( Entity_t* e )
{
  e->img = a_ImageLoad( "resources/assets/Enemies/Water_Slime.png" );
  e->base = 10;
  
  dVec3_t gravity  = {0};
  dVec3_t velocity = {0};
  dVec3_t force    = {0};

  float   mass          = 10.0f;
  float   max_speed     = 8.0f;
  float   max_force     = 0.2f;
  uint8_t takes_gravity = 1;

  float   static_friction = 0.0f;
  float   dynamic_friction = 0.0f;
  float   restitution = 0.0f;

  e->body = d_KinematicBodyCreate( gravity, velocity,
                                   force, mass,
                                   max_speed, max_force,
                                   takes_gravity, 
                                   static_friction,
                                   dynamic_friction,
                                   restitution );
 
  dVec3_t position = {0};
  dVec3_t scale    = {0};
  double  rotation = 0.0f;
  e->transform = d_TransformCreate( position, scale, rotation );
  
  STRNCPY( e->name, "Water_Slime", MAX_NAME_LENGTH );
}

void WhiteSlimeEntityInit( Entity_t* e )
{
  e->img = a_ImageLoad( "resources/assets/Enemies/White_Slime.png" );
  e->base = 10;
  
  dVec3_t gravity  = {0};
  dVec3_t velocity = {0};
  dVec3_t force    = {0};

  float   mass          = 10.0f;
  float   max_speed     = 8.0f;
  float   max_force     = 0.2f;
  uint8_t takes_gravity = 1;

  float   static_friction = 0.0f;
  float   dynamic_friction = 0.0f;
  float   restitution = 0.0f;

  e->body = d_KinematicBodyCreate( gravity, velocity,
                                   force, mass,
                                   max_speed, max_force,
                                   takes_gravity, 
                                   static_friction,
                                   dynamic_friction,
                                   restitution );
 
  dVec3_t position = {0};
  dVec3_t scale    = {0};
  double  rotation = 0.0f;
  e->transform = d_TransformCreate( position, scale, rotation );
  
  STRNCPY( e->name, "White_Slime", MAX_NAME_LENGTH );
}

