#include "tp6.h"
#include <stdlib.h>
#include <stdio.h>

unsigned char* allouer_pixels(entete_bmp *entete){
  unsigned char * p = malloc(entete->bitmap.hauteur * entete->bitmap.largeur * (entete->bitmap.profondeur/8));
  return p;
} 
