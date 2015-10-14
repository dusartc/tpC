#include "tp6.h"
#include <stdio.h>
#include <unistd.h> 

int lire_deux_octets(int fd, uint16 *val){
  return read(fd, val, 2); 
}

int lire_quatre_octets(int fd, uint32 *val){
  return read(fd, val, 4);
}

int lire_entete(int de, entete_bmp *entete){
  uint16 * val2;
//  uint32 * val4;
  lire_deux_octets(de,val2);
  entete->fichier.signature = *val2;
  return 0;
}
