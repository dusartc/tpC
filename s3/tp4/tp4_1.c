#include <stdlib.h>
#include <string.h>

char * miroir (const char *s){
  int len = strlen(s)+1;
	char * ans = malloc(sizeof(char)*len);
  int i;
	for(i=0;i<len-1;i++){
		ans[i] = s[len-i-1];
	}	
  ans[i]='\0';
	return ans;
}

