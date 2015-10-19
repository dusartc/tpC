#include <stdio.h>
#include "tp6.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
  int t = open("test24.bmp",O_RDONLY);
  int p = open("test25.bmp",O_RDWR | O_CREAT,0755);
  /*
   *entete_bmp bmp;
   *lire_entete(t,&bmp);
   *printf("%d\n",bmp.bitmap.profondeur);
   *printf("%d\n",verifier_entete(&bmp));
   *unsigned char * c = allouer_pixels(&bmp);
   *c++;
   */
  copier_bmp(t,p);
  return 0;
}
