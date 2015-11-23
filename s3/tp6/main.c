#include <stdio.h>
#include "tp6.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char **argv){
  int t,p;
  printf("t : %s\n",argv[argc-2]);
  printf("p : %s\n",argv[argc-1]);
  t = open(argv[argc-2],O_RDONLY);
  p = open(argv[argc-1],O_WRONLY | O_CREAT ,0666);
  if(t==-1)
    printf("t null\n");
  if(p==-1)
    printf("p null\n");
  copier_bmp(t,p,argv,argc);
  return 0;
}
