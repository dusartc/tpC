#include "tp6.h"
#include <unistd.h>

int ecrire_deux_octets(int fd, uint16 val){
  return write(fd,&val,2);
}

int ecrire_quatre_octets(int fd, uint32 val){
  return write(fd,&val,4);
}

int ecrire_entete(int vers, entete_bmp *entete){
  ecrire_deux_octets(vers,entete->fichier.signature);
  ecrire_quatre_octets(vers,entete->fichier.taille_fichier);
  ecrire_quatre_octets(vers,entete->fichier.reserve);
  ecrire_quatre_octets(vers,entete->fichier.offset_donnees);

  ecrire_quatre_octets(vers,entete->bitmap.taille_entete);
  ecrire_quatre_octets(vers,entete->bitmap.largeur);
  ecrire_quatre_octets(vers,entete->bitmap.hauteur);
  ecrire_deux_octets(vers,entete->bitmap.nombre_plans);
  ecrire_deux_octets(vers,entete->bitmap.profondeur);
  ecrire_quatre_octets(vers,entete->bitmap.compression);
  ecrire_quatre_octets(vers,entete->bitmap.taille_donnees_image);
  ecrire_quatre_octets(vers,entete->bitmap.resolution_horizontale);
  ecrire_quatre_octets(vers,entete->bitmap.resolution_verticale);
  ecrire_quatre_octets(vers,entete->bitmap.taille_palette);
  ecrire_quatre_octets(vers,entete->bitmap.nombre_de_couleurs_importantes);
  return 0;
}

