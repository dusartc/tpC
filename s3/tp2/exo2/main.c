#include <stdio.h>
#include "exo2.h"

int main(){
	struct rat a = {3,1};
	struct rat b = {4,1};
	
	struct rat tmp = rat_produit(a,b);
	printf("%d/%d\n",tmp.num,tmp.den);


	tmp = rat_somme(a,b);
	printf("%d/%d\n",tmp.num,tmp.den);

	
	struct rat l[] = {a,b,tmp};
	tmp = rat_plus_petit(l);
	printf("%d/%d\n",tmp.num,tmp.den);

	return 0;
}
