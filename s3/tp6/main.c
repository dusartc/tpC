#include <stdio.h>
#include "tp6.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
  open("test24.bmp",O_RDONLY);

  return 0;
}
