#include "tp7.h"
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int nom_correspond(const char *chemin, const char *motif){
  char *idx = rindex(chemin,'/');
  idx++;
  return strcmp(idx,motif) == 0;
}

int type_correspond(const struct stat *buf, char type){
  if(strcmp(&type,"f")==0)
    return S_ISREG(buf->st_mode);
  if(strcmp(&type,"d")==0)
    return S_ISDIR(buf->st_mode);
  if(strcmp(&type,"l")==0)
    return S_ISLNK(buf->st_mode);
  if(strcmp(&type,"b")==0)
    return S_ISBLK(buf->st_mode);
  if(strcmp(&type,"c")==0)
    return S_ISCHR(buf->st_mode);
  if(strcmp(&type,"p")==0)
    return S_ISFIFO(buf->st_mode);
  if(strcmp(&type,"s")==0)
    return S_ISSOCK(buf->st_mode);
  return -1;
}

int executable(const struct stat *buf){
  return (buf->st_mode & S_IRWXU) == S_IXUSR;
}

int vide(const struct stat *buf){
  return buf->st_size == 0;
}

int plus_recent(const struct stat *buf, const char *fichier_reference){
  struct stat fichier;
  int tmp = stat(fichier_reference,&fichier);
  if(tmp==-1){
    printf("fail to open fichier_reference");
    return -1;
  }
  return difftime(buf->st_mtim.tv_sec,fichier.st_mtim.tv_sec) < 0;
}
