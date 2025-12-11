#ifndef __ISO_H__
#define __ISO_H__

#include <Archimedes.h>

void ISO_Render_Init( void );
void ISO_Object_Logic( float dt );
void ISO_Draw_Objects( void );
void ISO_Clear( void );

void ISO_Convert( int x, int z, int* sx, int* sy );
void ISO_Add_Object( int x, int z, int sx, int sy, aImage_t* img );

#endif

