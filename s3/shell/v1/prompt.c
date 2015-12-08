#include "shell.h"
#include <stdlib.h>

void affiche_prompt(){
  char * u = getenv("USER");
  char * p = malloc(100);
  p = getcwd(p,100); 
  char h[10];
  int i = gethostname(h,10);
  i++;
  printf("[%s@%s]-[%s] -> ",u,h,p);
  fflush(stdout);
  free(p);
}
