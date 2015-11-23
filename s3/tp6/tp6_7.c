#include "tp6.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void afficher_entete(entete_bmp *entete);

int copier_bmp(int de, int vers, char **argv, int argc){
  entete_bmp entete;
  unsigned char *pixels;

  lire_entete(de, &entete);
  pixels = allouer_pixels(&entete);
  lire_pixels(de, &entete, pixels);

  //afficher_entete(&entete);

  t(&entete,pixels,argv,argc,1);

  ecrire_entete(vers, &entete);
  ecrire_pixels(vers, &entete, pixels);

  free(pixels);
  return 1;
}

int t(entete_bmp *entete, unsigned char *pixels, char **argv, int argc, int idx){
  //printf("%d %d\n",argc,idx);
  if(idx>=argc){
    return 0;
  }
  else if(strcmp(argv[idx],"-r")==0){
    rouge(entete,pixels);
    return t(entete,pixels,argv,argc,++idx);
  }
  else if(strcmp(argv[idx],"-n")==0){
    negatif(entete,pixels);
    return t(entete,pixels,argv,argc,++idx);
  }
  else if(strcmp(argv[idx],"-b")==0){
    noir_et_blanc(entete,pixels);
    return t(entete,pixels,argv,argc,++idx);
  }
  else if(strcmp(argv[idx],"-s")==0){
    moitie(entete,pixels,1);
    return t(entete,pixels,argv,argc,++idx);
  }
  else if(strcmp(argv[idx],"-i")==0){
    moitie(entete,pixels,0);
    return t(entete,pixels,argv,argc,++idx);
  }
  return 0;
}

void afficher_entete(entete_bmp *entete){
	printf("signature : %d\ntaille fichier : %d\nreserve : %d\noffset donnees : %d\n\ntaille entete : %d\nlargeur : %d\nhauteur : %d\nnombre plans : %d\nprofondeur : %d\ncompressions : %d\ntaille donnees image : %d\nresolution horizontale : %d\nresolution verticale : %d\ntaille palette : %d\nnombre de couleurs importantes : %d\n",entete->fichier.signature,entete->fichier.taille_fichier,entete->fichier.reserve,entete->fichier.offset_donnees,entete->bitmap.taille_entete,entete->bitmap.largeur,entete->bitmap.hauteur,entete->bitmap.nombre_plans,entete->bitmap.profondeur,entete->bitmap.compression,entete->bitmap.taille_donnees_image,entete->bitmap.resolution_horizontale,entete->bitmap.resolution_verticale,entete->bitmap.taille_palette,entete->bitmap.nombre_de_couleurs_importantes);
}	
