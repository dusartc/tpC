#include "tp6.h"

int verifier_entete(entete_bmp *entete){
  return entete->bitmap.profondeur == 24;
}
