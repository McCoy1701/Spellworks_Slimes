#ifndef __ISO_H__
#define __ISO_H__

#include <Archimedes.h>

void ISO_Init( void );
void ISO_Logic( float dt );
void ISO_Draw( void );
void ISO_Clear( void );

void ISO_Convert( float x, float z, float* sx, float* sy );
void ISO_AddAnimatedObject( float x, float z, float sx, float sy,
                            aAnimation_t* anim, int layer );
void ISO_AddStaticObject( float x, float z, float sx, float sy,
                          aImage_t* img, int layer );

int ISO_CheckBounds( float x, float z );

#endif

