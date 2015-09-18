#include <stdio.h>
#include <math.h>

int incr(int t[8]){
	for (int i = 0; i < 8; ++i) {
		if (t[i] == 0){
			t[i] = 1;
			return 0;
		}else{
			t[i]=0;
		}
	}return -1;
}

void init(int nombre){
	int tab[8];
	while(i < 8) {
 		if(nombre > 0) {
		t[i] = nombre % 2;
		nombre = nombre / 2;
		i = i + 1;
		}
		else {
		t[i] = 0;
		i = i + 1;
		}	
	}

int main(void){
	int tab[8];
	for (int i = 0; i < 255; ++i){
		init(i);
		incr(tab);
		int somme = 0;
		// for (int j = 8; j > 1; --j){
		// 	printf("%d\n", tab[j]);
		// }printf("\n");
	}return 0;
}

