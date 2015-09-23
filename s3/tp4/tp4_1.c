#include <stdlib.h>

char * miroir (const char *s){
	int len;
	for(int i=0;s[i]!='\0';i++)
		len=i;
	char * ans = malloc(sizeof(char)*len);
	for(int i=0;i<=len;i++){
		ans[i] = s[len-i];
	}	
	return ans;
}
