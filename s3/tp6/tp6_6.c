#include "tp6.h"
#include <unistd.h>

int ecrire_pixels(int vers, entete_bmp *entete, unsigned char *pixels){
  int s = entete->bitmap.hauteur * entete->bitmap.largeur * (entete-> bitmap.profondeur/8);
  return write(vers, pixels, s);
}
