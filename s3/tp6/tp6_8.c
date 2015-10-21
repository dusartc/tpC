#include "tp6.h"

void rouge(entete_bmp *entete, unsigned char *pixels){
  int s = entete->bitmap.resolution_horizontale * entete->bitmap.resolution_verticale;
  int i;
  for(i = 0;i<s;i+=3){
    pixels[i]=0;
    pixels[i+1]=0;
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
  int m=0;
  for(i = 1;i<s;i+=3){
    m=(pixels[i]+pixels[i+1]+pixels[i+2])/3;
    pixels[i]=m;
    pixels[i+1]=m;
    pixels[i+2]=m; 
  }
}
