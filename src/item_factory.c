#include <Archimedes.h>
#include <Daedalus.h>

#include "defines.h"
#include "item_factory.h"
#include "items_init.h"
#include "structs.h"

extern World_t world;

static Item_t* SpawnItem( void );
static Item_Init_Func_t* GetInitFunc( const char* name );
static void AddInitFunc(const char* name, void (*init)( Item_t* i ) );

static Item_Init_Func_t head, *tail;

void ItemFactoryInit( void )
{
  memset( &head, 0, sizeof( Item_Init_Func_t ) );
  tail = &head;
  
  AddInitFunc( "Blue_Drink", BlueDrinkItemInit );
  AddInitFunc( "Orange_Drink", OrangeDrinkItemInit );
  AddInitFunc( "Green_Drink", GreenDrinkItemInit );
  AddInitFunc( "Red_Drink", RedDrinkItemInit );
  AddInitFunc( "Burger", BurgerItemInit );
  AddInitFunc( "Fries", FriesItemInit );
  AddInitFunc( "White_Cake", WhiteCakeItemInit );
  AddInitFunc( "Chocolate_Cake", ChocolateCakeItemInit );
  AddInitFunc( "Chocolate_Bar", ChocolateBarItemInit );
  AddInitFunc( "Strawberry_Chocolate_Bar", StrawberryChocolateBarItemInit );
  AddInitFunc( "White_Chocolate_Bar", WhiteChocolateBarItemInit );
  AddInitFunc( "Grilled_Cheese", GrilledCheeseItemInit );
  AddInitFunc( "Strawberry_Ice_Cream_Cone", StrawberryIceCreamConeItemInit );
  AddInitFunc( "Mint_Ice_Cream_Cone", MintIceCreamConeItemInit );
  AddInitFunc( "Vanilla_Ice_Cream_Cone", VanillaIceCreamConeItemInit );
  AddInitFunc( "Chocolate_Ice_Cream_Cone", ChocolateIceCreamConeItemInit );
  AddInitFunc( "Apple", AppleItemInit );
  AddInitFunc( "Orange", OrangeItemInit );
  AddInitFunc( "Pear", PearItemInit );
  AddInitFunc( "Grape", GrapeItemInit );
  AddInitFunc( "Peach", PeachItemInit );
  AddInitFunc( "Blackberry", BlackberryItemInit );
  AddInitFunc( "Banana", BananaItemInit );
  AddInitFunc( "Milk", MilkItemInit );
  AddInitFunc( "Strawberry_Milk", StrawberryMilkItemInit );
  AddInitFunc( "Chocolate_Milk", ChocolateMilkItemInit );
  AddInitFunc( "Blue_Candy", BlueCandyItemInit );
  AddInitFunc( "Purple_Candy", PurpleCandyItemInit );
  AddInitFunc( "Red_Candy", RedCandyItemInit );
  AddInitFunc( "Pancakes", PancakesItemInit );
  AddInitFunc( "Salad", SaladItemInit );
}

Item_t* ItemInit( const char* name )
{
  Item_t* i = SpawnItem();

  GetInitFunc( name )->init(i);

  d_ArrayAppend( world.ground_item_pool, i );
  world.stats.tl_ground_items++;

  return i;
}

void ItemPoolRemove( Item_t* i )
{
  d_ArrayRemoveByReference( world.ground_item_pool, i );

  ItemDestroy( i );
}

void ItemDestroy( Item_t* i )
{
  if ( i == NULL ) return;

  if ( i->img )
  {
    a_ImageFree( i->img );
    i->img = NULL;
  }

  i = NULL;
}

static Item_t* SpawnItem( void )
{
  if ( world.ground_item_pool->count < MAX_GROUND_ITEMS )
  {
    Item_t* i = malloc( sizeof( Item_t ) );
    memset( i, 0, sizeof( Item_t ) );

    return i;
  }

  LOG("TOO MANY ITEMS!");
  return NULL;
}

static Item_Init_Func_t* GetInitFunc( const char* name )
{
  Item_Init_Func_t* init_func;
  for ( init_func = head.next; init_func != NULL; init_func = init_func->next )
  {
    if ( strcmp( init_func->name, name ) == 0 )
    {
      return init_func;

    }
  }

  char log_msg[MAX_NAME_LENGTH];
  snprintf( log_msg, MAX_NAME_LENGTH, "Uknown Item: %s", name );
  LOG( log_msg );

  return NULL;
}

static void AddInitFunc(const char* name, void (*init)( Item_t* i ) )
{
  Item_Init_Func_t* init_func = malloc( sizeof( Item_Init_Func_t ) );
  memset( init_func, 0, sizeof( Item_Init_Func_t ) );

  tail->next = init_func;
  tail = init_func;

  STRNCPY( init_func->name, name, MAX_NAME_LENGTH );
  init_func->init = init;
}

