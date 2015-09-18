#include <stdio.h>
#include "tp3.h"

int main(){
	char s[] = "ajr";
	char t[] = "bjr";
	int tmp = mon_strncmp(s,t);
	printf("%d\n", tmp);

	return 0;
}
