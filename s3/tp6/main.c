#include <stdio.h>
#include "tp6.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv){
  int t = open("test24.bmp",O_RDONLY);
  int p = open("test25.bmp",O_RDWR | O_CREAT,0755);
  copier_bmp(t,p,argv,argc);
  return 0;
}
