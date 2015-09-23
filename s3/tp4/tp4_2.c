#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char * saisie (){
	char c;
	char ans[256];
	int i=0;
	do{
		c=getchar();
		ans[i++]=c;
	}while(! isspace(c));
	char * a = malloc(i);
	for(int j=0;j<i;j++){
		a[j]=ans[j];
	}
	//printf("%s",a);
	return a;
}
