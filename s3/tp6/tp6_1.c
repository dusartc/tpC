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
  uint16 val2;
  uint32 val4;
  lire_deux_octets(de,&val2);
  entete->fichier.signature = val2;
  lire_quatre_octets(de,&val4);
  entete->fichier.taille_fichier = val4;
  lire_quatre_octets(de,&val4);
  entete->fichier.reserve = val4;
  lire_quatre_octets(de,&val4);
  entete->fichier.offset_donnees = val4;

  lire_quatre_octets(de,&val4);
  entete->bitmap.taille_entete = val4;
  lire_quatre_octets(de,&val4);
  entete->bitmap.largeur = val4;
  lire_quatre_octets(de,&val4);
  entete->bitmap.hauteur = val4;
  lire_deux_octets(de,&val2);
  entete->bitmap.nombre_plans = val2;
  lire_deux_octets(de,&val2);
  entete->bitmap.profondeur = val2;
  lire_quatre_octets(de,&val4);
  entete->bitmap.compression = val4;
  lire_quatre_octets(de,&val4);
  entete->bitmap.taille_donnees_image = val4;
  lire_quatre_octets(de,&val4);
  entete->bitmap.resolution_horizontale = val4;
  lire_quatre_octets(de,&val4);
  entete->bitmap.resolution_verticale = val4;
  lire_quatre_octets(de,&val4);
  entete->bitmap.taille_palette = val4;
  lire_quatre_octets(de,&val4);
  entete->bitmap.nombre_de_couleurs_importantes = val4;
  return 0;
}
