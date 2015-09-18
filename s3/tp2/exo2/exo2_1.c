#include "rat.h"

struct rat rat_produit(struct rat n1, struct rat n2){
	struct rat ans = {(n1.den * n2.den),(n1.num * n2.num)};
	return ans;
}
