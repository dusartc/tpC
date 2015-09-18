#include "tp3.h"

char *mon_strcat(char *s1, const char *s2){
	int s1len = mon_strlen(s1);
	int i=0;
	while(s2[i] != '\0'){
		s1[i+s1len]=s2[i];
		i++;
	}	
	return s1;
}
