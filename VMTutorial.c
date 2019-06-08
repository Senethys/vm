//https://www.youtube.com/watch?v=DUNkdl0Jhgs

/* Includes  */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* DATABTYPES */

//Same space can be references as these values
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

}

STACK stack_push(STACK *s, OBJECT o) {
  s.stack[s.top++] = o;
  return s.top;
}

STACK stack_pop(STACK *s) {
}

STACK stack_peek(STACK *s) {
}

/* Main Algorithm */
int main (int argc, char **argv) {

  printf("Running...")
  return 0;
}
