#include <stdio.h>
#include "tp3.h"

int main(){
	char *s = "chehat";
	char *t = "hat";
	char *p = mon_strstr(s,t);

	printf("%p %p\n",p,&s[3]);	

	char ss[10] = "aaa";
	char *pp = mon_strcat(ss,t);
	printf("%s\n",pp);

	return 0;
}
