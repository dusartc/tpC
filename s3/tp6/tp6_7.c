#include "tp6.h"
#include <stdlib.h>

int copier_bmp(int de, int vers){
  entete_bmp entete;
  unsigned char *pixels;

  lire_entete(de, &entete);
  pixels = allouer_pixels(&entete);
  lire_pixels(de, &entete, pixels);

  ecrire_entete(vers, &entete);
  ecrire_pixels(vers, &entete, pixels);

  free(pixels);
  return 1;
}
