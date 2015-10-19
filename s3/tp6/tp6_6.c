#include "tp6.h"
#include <unistd.h>

int ecrire_pixels(int vers, entete_bmp *entete, unsigned char *pixels){
  int s = entete->bitmap.resolution_verticale * entete->bitmap.resolution_horizontale;
  return write(vers, pixels, s);
}
