#include "tp6.h"
#include <stdlib.h>
#include <stdio.h>

unsigned char* allouer_pixels(entete_bmp *entete){
  unsigned char * p = malloc(entete->bitmap.taille_donnees_image);
  return p;
} 
