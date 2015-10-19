#include "tp6.h"
#include <unistd.h>

int lire_pixels(int de, entete_bmp *entete, unsigned char *pixels){
  int s = entete->bitmap.resolution_horizontale * entete->bitmap.resolution_verticale;
  return read(de,pixels,s);
}
