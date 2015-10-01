#include <stdlib.h>
#include <string.h>

char * miroir (const char *s){
  int len = strlen(s);
	char * ans = malloc(sizeof(char)*len);
  int i;
	for(i=0;i<len;i++){
		ans[i] = s[len-i-1];
	}	
	return ans;
}

