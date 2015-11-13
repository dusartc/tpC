#include "tp6.h"
#include <unistd.h>

int lire_pixels(int de, entete_bmp *entete, unsigned char *pixels){
  int s = entete->bitmap.hauteur * entete->bitmap.largeur * (entete->bitmap.profondeur/8);
  return read(de,pixels,s);
}
