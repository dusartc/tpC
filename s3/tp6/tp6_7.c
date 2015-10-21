#include "tp6.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int copier_bmp(int de, int vers, char **argv, int argc){
  entete_bmp entete;
  unsigned char *pixels;

  lire_entete(de, &entete);
  pixels = allouer_pixels(&entete);
  lire_pixels(de, &entete, pixels);

  t(&entete,pixels,argv,argc,1);

  ecrire_entete(vers, &entete);
  ecrire_pixels(vers, &entete, pixels);

  free(pixels);
  return 1;
}

int t(entete_bmp *entete, unsigned char *pixels, char **argv, int argc, int idx){
  printf("%d %d\n",argc,idx);
  if(idx>=argc){
    return 0;
  }
  else if(strcmp(argv[idx],"-r")==0){
    rouge(entete,pixels);
    return t(entete,pixels,argv,argc,++idx);
  }
  else if(strcmp(argv[idx],"-n")){
    negatif(entete,pixels);
    return t(entete,pixels,argv,argc,++idx);
  }
  else if(strcmp(argv[idx],"-b")){
    noir_et_blanc(entete,pixels);
    return t(entete,pixels,argv,argc,++idx);
  }
  return 0;
}
