#include <stdio.h>
#include <Archimedes.h>

#include "defines.h"
#include "entity.h"
#include "entity_logic/player.h"
#include "entity_factory.h"
#include "iso.h"
#include "main_menu.h"
#include "map.h"
#include "projectiles.h"
#include "structs.h"

static void Do_Cursor( void );

World_t world;

static void s0_Logic( float );
static void s0_Draw( float );

void Stage0Init( void )
{
  app.delegate.logic = s0_Logic;
  app.delegate.draw  = s0_Draw;

  world.stats.tl_entities = 0;  
  world.stats.tl_projectiles = 0;  
  
  Map_Init();

  ISO_Init();
  
  EntityFactoryInit();

  EntitiesInit();

  PlayerInit();

  a_WidgetsInit( "resources/widgets/inventory.auf" );
  app.active_widget = a_GetWidget( "inv_screen" );
}

static void s0_Logic( float dt )
{
  a_DoInput();
  
  if ( app.keyboard[ SDL_SCANCODE_ESCAPE ] == 1 )
  {
    app.keyboard[SDL_SCANCODE_ESCAPE] = 0;
    MainMenuInit();
  }

  if ( app.keyboard[A_R] == 1 )
  {
    app.keyboard[A_R] = 0;
    a_WidgetsInit( "resources/widgets/inventory.auf" );

  }
  
  if ( app.keyboard[A_T] == 1 )
  {
    app.keyboard[A_T] = 0;
    a_WidgetsInit( "resources/widgets/test.auf" );

  }
  
  ISO_Logic( dt );
  Do_Cursor();
  PlayerLogic( dt );

  a_DoWidget();
}

static void s0_Draw( float dt )
{
  ISO_Clear();
  Map_Draw();
  EntitiesDraw();
  ProjectileDraw();
  ISO_Draw();

  aColor_t color_something = { .r = 0, .g = 0, .b = 255, .a = 255 };
  aRectf_t rect_something = { .x = 100, .y = 100, .w = 32, .h = 32 };
  a_DrawFilledRect( rect_something, color_something );
  
  char fps_text[MAX_NAME_LENGTH];
  snprintf(fps_text, MAX_NAME_LENGTH, "%f", app.time.avg_FPS );
  
  aTextStyle_t fps_style = {
    .type = FONT_CODE_PAGE_437,
    .fg = white,
    .bg = black,
    .align = TEXT_ALIGN_CENTER,
    .wrap_width = 0,
    .scale = 1.0f,
    .padding = 0
  };

  a_DrawText( fps_text, 600, 100, fps_style );

  a_DrawWidgets();
}

static void Do_Cursor( void )
{
  double sx, sy;

  sx = app.mouse.x - ( (float)CELL_WIDTH / 2 );
  sy = app.mouse.y - ( (float)CELL_HEIGHT / 2 );

  sx -= MAP_RENDER_X_OFFSET;
  sy -= MAP_RENDER_Y_OFFSET;

  world.cursor_x = round( ( ( sx / CELL_WIDTH ) - ( sy / CELL_HEIGHT ) ) );
  world.cursor_y = round( ( ( sx / CELL_WIDTH ) + ( sy / CELL_HEIGHT ) ) );

}

