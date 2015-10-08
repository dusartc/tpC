#include "tp5.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

int traiter(int f, int *car, int *mot, int *lig){
  *car=0;*mot=0;*lig=0;
  char *buffer = malloc(sizeof(char)*80);
  int b;
  int i;
  while((b=read(f,buffer,80))!=0){
    for(i=0;i<b-1;i++){
      if(islower(buffer[i]) || isupper(buffer[i])){
        while((islower(buffer[i]) || isupper(buffer[i])) && i<(b-2)){
          i++;
          *car+=1;
        }
        *mot+=1;
        *car+=1;
      }
      if(buffer[i] == '\n'){
        *lig+=1;
      }
    }
  }
  *car-=1;
  *mot-=1; //end of file
  free(buffer);
  return 0;
}
