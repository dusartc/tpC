typedef struct{
  unsigned int free;
  unsigned int size;
  unsigned char *addr;
  unsigned char *next_chunk;
  unsigned char *previous_chunk;
}chunk;
