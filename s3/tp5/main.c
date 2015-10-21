#include <stdio.h>
#include <string.h>
#include "tp5.h"

int main(int argc, char **argv){
  int w=0;
  int l=0;
  int c=0;
  int idx=1;
  if(argc>1){
    for(idx=1;argv[idx][0] == '-' && argc>2;idx++){
      if(strstr(argv[idx],"l")){
        l=1;
      }    
      if(strstr(argv[idx],"w")){
        w=1;
      }    
      if(strstr(argv[idx],"c")){
        c=1;
      }    
    }
  }else{
    printf("not enough argument\n");
    return 1;
  }
  if(idx==1){
    w=1;l=1;c=1;
  }
  int *car = malloc(sizeof(int));
  int *mot = malloc(sizeof(int));
  int *lig = malloc(sizeof(int));
  for(idx=idx;idx<argc;idx++){
    int f = open(argv[idx], O_RDONLY);
    if(f==-1){
      perror("test");
      return 1;
    }
    if(argc == 1){
      f=0;
    }
    traiter(f,car,mot,lig);
    printf("    %s :\n",argv[idx]);
    if(l==1){
      printf("ligne : %d\n",*lig);
    }
    if(w==1){
      printf("mot : %d\n",*mot);
    }
    if(c==1){
      printf("car : %d\n",*car);
    }
  }
  free(car);free(mot);free(lig);
  return 0;
}
