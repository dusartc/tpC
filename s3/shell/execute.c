#include "ligne_commande.h"
#include "shell.h"

void erreur(int status);

void execute_ligne_commande(){
  int flag;
  int nb;
  char *** result = ligne_commande(&flag,&nb);
  if(result != NULL){
    if(nb>1){
      affiche(result);
      int i;
      for(i=0;i<nb;i++){
        int f, status, tab_pipe[nb][2];
        if(pipe(tab_pipe[i]) == -1){
          perror("pipe");
          exit(1);
        }
        if((f=fork())==0){
          if(!(i>0 && i<nb)){
            close(tab_pipe[i][1]);
            printf("fermeture de l'entree du tuyau pour %s\n",result[i][0]);
          }
          if(i==nb-1){
            printf("fermeture de la sortie du tuyau pour %s\n",result[i][0]);
            close(tab_pipe[i][0]);
          }
        lance_commande((i>0 && i<nb)?tab_pipe[i][1]:0,(i==nb-1)?1:tab_pipe[i+1][0],result[i][0],result[i]);
        }
        waitpid(f,&status,0);
        /*
         *if((f2=fork())==0){
         *  close(pipefd[0]);
         *  lance_commande(pipefd[1],(i>0 && i<nb-1)?pipefd[0]:1,result[i+1][0],result[i+1]);
         *}
         *waitpid(f2,&status,0);
         */
      }
    } else {
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
    }
    libere(result);
  }
}


void erreur(int status){
  status++;
}
