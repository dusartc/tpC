#include "tp6.h"

/*
 *void rouge(entete_bmp *entete, unsigned char *pixels){
 *  int s = entete->bitmap.hauteur * entete->bitmap.largeur * (entete->bitmap.profondeur/8);
 *  int i;
 *  for(i = 0;i<s;i+=3){
 *    pixels[i]=0;
 *    pixels[i+1]=0;
 *  }
 *}
 */

void negatif(entete_bmp *entete, unsigned char *pixels){
  int s = entete->bitmap.hauteur * entete->bitmap.largeur * (entete->bitmap.profondeur/8);
  int i;
  for(i = 1;i<s;i++){
    pixels[i]=~pixels[i];
  }
}

void noir_et_blanc(entete_bmp *entete, unsigned char *pixels){
  int s = entete->bitmap.hauteur * entete->bitmap.largeur * (entete->bitmap.profondeur/8);
  int i;
  int m=0;
  for(i = 1;i<s;i+=3){
    m=(pixels[i]+pixels[i+1]+pixels[i+2])/3;
    pixels[i]=m;
    pixels[i+1]=m;
    pixels[i+2]=m; 
  }
}


void rouge(entete_bmp *entete, unsigned char *pixels){
	int i;
	int j;
	for(i=0;i<(int)entete->bitmap.hauteur;++i){
		for(j=0;j<(int)entete->bitmap.largeur;++j){
			pixels[0]=0;
			pixels[1]=0;
			pixels+=3;
		}
		if (entete->bitmap.largeur*(entete->bitmap.profondeur/8*sizeof(char))%4!=0){
			pixels+= (4-entete->bitmap.largeur*(entete->bitmap.profondeur/8*sizeof(char))%4);
		}
	}
}
