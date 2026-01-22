#ifndef __UTILS_H__
#define __UTILS_H__

#include "structs.h"

void CalculateScreenPos( aImage_t* img, int base, int* sx, int* sz );
void LoadAnimation( int w, int h, int frame_count,
                    uint32_t frame_duration,
                    char* filename, aAnimation_t** anim );

int ConvertEnemyNameToId( const char* name );

#endif

