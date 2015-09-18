#include "tp3.h"
#include <stddef.h>

char *mon_strchr(char *s, int c){
	int i=0;
	while(s[i] != '\0' && s[i] != c){
		i++;
	}
	if(s[i] == c)
		return &s[i];
	return NULL;
}
