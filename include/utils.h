#ifndef __UTILS_H__
#define __UTILS_H__

#include "structs.h"

void CalculateScreenPos( Entity_t* e, int* sx, int* sy );
void LoadAnimation( int w, int h, int frame_count,
                    uint32_t frame_duration,
                    char* filename, aAnimation_t** anim );

#endif

