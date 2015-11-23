#include "tp6.h"
#include <sys/types.h>
#include <unistd.h>

int lire_pixels(int de, entete_bmp *entete, unsigned char *pixels){
  lseek(de, entete->fichier.offset_donnees, SEEK_SET);
  int s = entete->bitmap.taille_donnees_image;
  return read(de,pixels,s);
}
