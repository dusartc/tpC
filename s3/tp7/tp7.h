#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>


enum {
  NAME,
  TYPE,
  EXEC,
  EMPTY,
  NEWER,
  INVALID,
};

typedef struct {
  int type;
  union {
    const char *motif;
    const char *chemin;
    char type_fichier;
  } operande;
} expression;

void traiter_fichier(const char *chemin, const expression *exp, int suivre_lien);
//void parcourir_repertoire(const char *chemin);

int nom_correspond(const char *chemin, const char *motif);
int type_correspond(const struct stat *buf, char type);
int executable(const struct stat *buf);
int vide(const struct stat *buf);
int plus_recent(const struct stat *buf, const char *fichier_reference);

void type_fichier(const char *chemin, const expression *exp, int suivre_lien);
void parcourir_repertoire(const char *chemin, const expression *exp, int suivre_lien);

