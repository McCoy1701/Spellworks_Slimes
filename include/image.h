#ifndef __IMAGE_H__
#define __IMAGE_H__

#include <Archimedes.h>

void load_tiles( aImage_t** img_cache,
                 int width, int height,
                 int cell_width, int cell_height,
                 const char* filename );

#endif

