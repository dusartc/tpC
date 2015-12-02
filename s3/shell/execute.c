#include "ligne_commande.h"
#include "shell.h"
#include <stdlib.h>

void erreur(int status);

void execute_ligne_commande(){
  int * flag = malloc(sizeof(int));
  int * nb = malloc(sizeof(int));
  char *** result = ligne_commande(flag,nb);
  if(result == NULL)
    exit(1);
  char ** argv = result[0];
  affiche(result);
  if(*flag == 0){
    //bloquant
    printf("bloquant\n");
    if(fork() == 0){
      execvp(argv[0],argv);
      perror("exevp");
      exit(1);
    } else {
      int status[1];
      wait(status);
      erreur(status[1]);
    }
  } else if(*flag == 1){
    // non bloquant
    printf("non bloquant\n");
    int f;
    if((f = fork())==0){
      //fils
      execvp(argv[0],argv);
      perror("execvp");
      exit(1);
    } else {
      int status[1];
      waitpid(f,status,WNOHANG);
      erreur(status[1]);
    }
  } else if(*flag == -1){
    //chelou
    printf("commande nul\n"); 
  } else {
    //fail
    printf("fail\n");
    exit(EXIT_FAILURE);
  } 
  free(nb);
  free(flag);
  libere(result);
}


void erreur(int status){
  status++;
}
