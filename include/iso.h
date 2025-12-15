#ifndef __ISO_H__
#define __ISO_H__

#include <Archimedes.h>

void ISO_Init( void );
void ISO_Logic( float dt );
void ISO_Draw( void );
void ISO_Clear( void );

void ISO_Convert( int x, int z, int* sx, int* sy );
void ISO_AddObject( int x, int z, int sx, int sy, aImage_t* img, int layer );

#endif

