#include "shell.h"

int lance_commande(int in, int out, char *com, char **argv){
  if(in != 0){
    printf("redirection entree standard pour la commande %s\n",com);
    dup2(0,in);
  }
  if(out != 1){
    printf("redirection sortie standard pour la commande %s\n",com);
    dup2(1,out);
  }
  execvp(com,argv);
  printf("erreur avec %s",com);
  perror("exec");
  exit(1);
}
