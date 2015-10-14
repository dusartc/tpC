#include "tp6.h"
#include <stdlib.h>

unsigned char* allouer_pixels(entete_bmp *entete){
  unsigned char * p = malloc(sizeof(int)*3*entete->bitmap.resolution_horizontale*entete->bitmap.resolution_verticale);
  return p;
} 
