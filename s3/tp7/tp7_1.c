#include "tp7.h"
#include <stdlib.h>
#include <string.h>

void traiter_fichier(const char *chemin){
  printf("%s\n",chemin);
}

void parcourir_repertoire(const char *chemin){
  DIR *dir = opendir(chemin);
  struct dirent *dirent;

  while((dirent = readdir(dir)) != NULL){
    if(dirent->d_type == DT_DIR){
      //directory
      printf("directory : %s/%s\n",chemin,dirent->d_name);
      if(strcmp(dirent->d_name,".") != 0 && strcmp(dirent->d_name,"..") != 0){
        char *s = malloc(strlen(chemin) + strlen(dirent->d_name) + 2);
        strcpy(s,chemin);
        parcourir_repertoire(strcat(strcat(s,"/"),dirent->d_name));
        free(s);
      }
    } else {
      //file
      char *t = malloc(strlen(chemin) + strlen(dirent->d_name)+2);
      strcpy(t,chemin);
      traiter_fichier(strcat(strcat(t,"/"),dirent->d_name));
      free(t);
    }
  } 
  free(dir);
  free(dirent);
}
