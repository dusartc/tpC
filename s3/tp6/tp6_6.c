#include "tp6.h"
#include <sys/types.h>
#include <unistd.h>

int ecrire_pixels(int vers, entete_bmp *entete, unsigned char *pixels){
  lseek(vers, entete->fichier.offset_donnees, SEEK_SET);
  int s = entete->bitmap.taille_donnees_image;
  return write(vers, pixels, s);
}
