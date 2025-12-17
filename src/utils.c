
#include <Archimedes.h>

#include "structs.h"

void CalculateScreenPos( Entity_t* e, int* sx, int* sy )
{
  *sx = CELL_WIDTH / 2;
  *sx -= e->img->rect.w / 2;
  
  *sy = CELL_HEIGHT / 2;
  *sy -= e->img->rect.h;
  *sy -= e->base;
}

