#include <stdio.h>

#include <Archimedes.h>

#include "stage.h"

void aMainloop( void )
{
  float dt = a_GetDeltaTime();
  a_TimerStart( app.time.FPS_cap_timer );
  a_GetFPS();
  a_PrepareScene();
  
  app.delegate.logic( dt );
  app.delegate.draw( dt );
  
  a_PresentScene();
  app.time.frames++;
  
  if ( app.options.frame_cap )
  {
    int frame_tick = a_TimerGetTicks( app.time.FPS_cap_timer );
    if ( frame_tick < LOGIC_RATE )
    {
      SDL_Delay( LOGIC_RATE - frame_tick );
    }
  }
}

int main( void )
{
  a_Init( SCREEN_WIDTH, SCREEN_HEIGHT, "Archimedes" );

  aInitGame();

  while( app.running ) {
    aMainloop();
  }
  
  a_Quit();

  return 0;
}

