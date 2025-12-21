#ifndef __MAP_H__
#define __MAP_H__

void Map_Init( void );
void Map_Draw( void );

int IsGround( int x, int z );
int CheckPlayersBounds( void );
int CheckMapBounds( int x, int z );

#endif

