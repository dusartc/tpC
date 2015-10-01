#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
      char * b = miroir(a);
			printf("%s\n",b);
      free(a);
      free(b);
			return 0;
		}
		char * a = saisie();
		printf("%s",a);
    free(a);
		return 0;
	}
	if(strstr(argv[1],"m") != NULL){
		if(argc < 3){
			printf("mauvaise utilisation\n");
			return 1;
		}
    char * t = miroir(argv[2]);
		printf("%s\n",t);
    free(t);
		return 0;
	}

}

/*
 *int main(int argc, char **argv){
 *  while(1)
 *    main2(argc,argv);
 *  return 0;
 *}
 */
