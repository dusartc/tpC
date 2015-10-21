#include "tp6.h"
#include <stdlib.h>
#include <stdio.h>

unsigned char* allouer_pixels(entete_bmp *entete){
  unsigned char * p = malloc(sizeof(char)*3*entete->bitmap.resolution_horizontale*entete->bitmap.resolution_verticale);
  return p;
} 
