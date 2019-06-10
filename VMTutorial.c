//https://www.youtube.com/watch?v=DUNkdl0Jhgs

/* Includes  */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/* DATABTYPES */
//Same space can be references as these values Basically datatype
typedef struct OBJECT_t {
  uint8_t type;

  union {
    uint8_t u8;
    int8_t i8;
    uint32_t u32;
    int32_t i32;
    void *ptr;
  };
} OBJECT;

typedef struct STACK_t {
    int top;
    int size;
    OBJECT *stack;
} STACK;


STACK stack_new(int size){
  STACK s;
  s.top = 0;
  s.size = size;
  s.stack = (OBJECT *)malloc(sizeof(OBJECT) * size);
  return s;
}

int stack_push(STACK *s, OBJECT o) {
  s->stack[s->top++] = o;
  return s->top;
}

OBJECT stack_pop(STACK *s) {
  return s->stack[--(s->top)];
}

OBJECT stack_peek(STACK *s) {
  return s->stack[s->top - 1];
}

void usage() {
  printf("Run again.");
  exit(01);
}

uint8_t *load_file(char *filename) {
  FILE *f;
  int size;
  uint8_t *code = NULL;
  struct stat st; //??????
  if((f = fopen(filename, "r"))) {
    fstat(fileno(f), &st);
    //Add memeory for the size of st where st will be a pointer to a int byte
    code = (uint8_t *)malloc(st.st_size);
    fread((void *)code, 1, st.st_size, f);
  } else {
    usage();
  }
  return code;
}

/* Main Algorithm */
int main (int argc, char **argv) {
  printf("Running...");
  uint8_t *code;

  if(argc != 2) {
    usage();
  }
  code = load_file(argv[1]);
  return 0;
}
