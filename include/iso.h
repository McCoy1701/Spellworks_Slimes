#ifndef __ISO_H__
#define __ISO_H__

#include <Archimedes.h>
#include <Daedalus.h>

void ISO_Init( void );
void ISO_Logic( float dt );
void ISO_Draw( void );
void ISO_Clear( void );

void ISO_Convert( dVec3_t pos, float* sx, float* sy );
void ISO_AddAnimatedObject( dVec3_t pos, float sx, float sy,
                            aAnimation_t* anim, int layer );
void ISO_AddStaticObject( dVec3_t pos, float sx, float sy,
                          aImage_t* img, int layer );

int ISO_CheckBounds( dVec3_t pos );

#endif

