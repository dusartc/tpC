#include "tp3.h"
#include <stddef.h>

char *mon_strstr(char *haystack, char *needle){
	char *pc = mon_strchr(haystack,needle[0]);
	if(pc != NULL){
		int i=0;
		while(pc[i] == needle[i] && needle[i] !='\0'){
			i++;
		}
		if(pc[i] == needle[i])
			return pc;
		else 
			return mon_strstr(&pc[i],needle);
	}
	return NULL;
}
