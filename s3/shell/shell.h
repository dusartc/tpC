#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include "ligne_commande.h"

void affiche_prompt();
char *** ligne_commande(int * flag, int * nb);
void execute_ligne_commande();
