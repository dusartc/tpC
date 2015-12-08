#include "shell.h"

int main(){
  while(1){
    affiche_prompt();
    execute_ligne_commande();
  }
  return 0;
}
