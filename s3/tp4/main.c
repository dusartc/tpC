#include <stdio.h>
#include <string.h>
#include "tp4.h"

int main(int argc, char **argv){
	if(argc < 2){
		printf("mauvaise utilisation\n");
		return 1;
	}
	if(argv[1][0] != '-'){
		printf("mauvaise utilisation\n");
		return 1;
	}
	if(strstr(argv[1],"s") != NULL){
		if(strstr(argv[1],"m") != NULL){
			char * a = saisie();
			printf("%s",miroir(a));
			return 0;
		}
		char * a = saisie();
		printf("%s",a);
		return 0;
	}
	if(strstr(argv[1],"m") != NULL){
		if(argc < 3){
			printf("mauvaise utilisation\n");
			return 1;
		}
		printf("%s\n",miroir(argv[2]));
		return 0;
	}

}
