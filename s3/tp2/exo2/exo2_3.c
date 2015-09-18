#include "rat.h"

struct rat rat_plus_petit(struct rat list[]){
	struct rat ans;
	double tmp = 0.0;
	double current = 25.0;
	int i = 0;
	while(list[i].den != 0){
		tmp = (double) list[i].num / (double) list[i].den;
		if(tmp < current){
			ans = list[i];
			current = tmp;
		}i++;
	}return ans;
}
