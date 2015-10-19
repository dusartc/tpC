#include "tp6.h"

void rouge(entete_bmp *entete, unsigned char *pixels){
  int s = entete->bitmap.resolution_horizontale * entete->bitmap.resolution_verticale;
  int i;
  for(i = 1;i<s;i++){
    if(i%3!=0){
      pixels[i]=0;
    }
  }
}

void negatif(entete_bmp *entete, unsigned char *pixels){
  int s = entete->bitmap.resolution_horizontale * entete->bitmap.resolution_verticale;
  int i;
  for(i = 1;i<s;i++){
    pixels[i]=~pixels[i];
  }
}

void noir_et_blanc(entete_bmp *entete, unsigned char *pixels){
  int s = entete->bitmap.resolution_horizontale * entete->bitmap.resolution_verticale;
  int i;
  for(i = 1;i<s;i++){
    
  }
}
