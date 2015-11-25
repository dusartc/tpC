#include "tp7.h"
#include <stdlib.h>
#include <string.h>

void traiter_fichier(const char *chemin, const expression *exp, int suivre_lien){
  if(exp->type != INVALID){
    if(exp->type == NAME){
      if(nom_correspond(chemin,exp->operande.motif)){
        printf("found corresponding name: chemin : %s, motif : \n",chemin,exp->operande.motif);
      }
    }
    else if(exp->type == TYPE){
      struct stat buf;
      stat(chemin,&buf);
      if(type_correspond(&buf,exp->operande.type_fichier)){
        printf("found corresponding type : %s\n",chemin);
      }
    }
    else if(exp->type == EXEC){
      struct stat buf;
      stat(chemin,&buf);
      if(executable(&buf)){
        printf("found executable : %s\n",chemin);
      }
    }
    else if(exp->type == EMPTY){
      struct stat buf;
      stat(chemin,&buf);
      if(vide(&buf)){
        printf("found empty : %s\n",chemin);
      }
    }
  }
}

void parcourir_repertoire(const char *chemin, const expression *exp, int suivre_lien){
  DIR *dir = opendir(chemin);
  struct dirent *dirent;

  while((dirent = readdir(dir)) != NULL){
    if(dirent->d_type == DT_DIR){
      //directory
      printf("directory : %s/%s\n",chemin,dirent->d_name);
      if(strcmp(dirent->d_name,".") != 0 && strcmp(dirent->d_name,"..") != 0){
        char *s = malloc(strlen(chemin) + strlen(dirent->d_name) + 1);
        strcpy(s,chemin);
        parcourir_repertoire(strcat(strcat(s,"/"),dirent->d_name), exp, suivre_lien);
        free(s);
      }
    } else {
      //file
      char *t = malloc(strlen(chemin) + strlen(dirent->d_name)+1);
      strcpy(t,chemin);
      traiter_fichier(strcat(strcat(t,"/"),dirent->d_name), exp, suivre_lien);
      free(t);
    }
  } 
  free(dir);
  free(dirent);
}
