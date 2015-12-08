#include "ligne_commande.h"
#include "shell.h"
#include <string.h>
#include <stdlib.h>

void erreur(int status);

void execute_ligne_commande(){
  int flag;
  int nb;
  char *** result = ligne_commande(&flag,&nb);
  if(result != NULL){
    char ** argv = result[0];
    if(strcmp(argv[0],"exit")==0)
      exit(1);
    affiche(result);
    int f;
    if((f=fork())==0){
      execvp(argv[0],argv);
      perror("execvp");
      exit(1);
    }
    int status;
    if(flag == 0){
      printf("bloquant\n");
      waitpid(f,&status,0);
    } else {
      printf("non bloquant\n");
      waitpid(f,&status,WNOHANG);
    }

    libere(result);
  }
}


void erreur(int status){
  status++;
}
