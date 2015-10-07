#include "lib.h"

unsigned int get_int(void *ptr){
  return (unsigned int) ptr;
}

void set_int(void *ptr, unsigned int val){
  ptr = val;
}

void set_chunk(chunk *c, unsigned char *ptr){

