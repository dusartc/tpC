#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char * saisie (){
    char *p = malloc(16*sizeof(char));
    char c;
    int i = 0;
    do{
        if(i%16 == 0){
            p = realloc(p,(i+16)*sizeof(char));
        }
        c = getchar();
        p[i++] = c;
    }while(!isspace(c));
    p=realloc(p,(++i)*sizeof(char));
    p[i]='\0';
    return p;
}
