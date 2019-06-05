#include <stdio.h>

/* 655 36 addressable units */

/* Unsigned shory */
/* UINT16_MAX- This is the maximum value that an unsigned 16-bit integer can contain */
uint16_t main_memory[UINT16_MAX]

/* Registers */
enum
{
  R_R0 = 0,
  R_R1 = 0,
  R_R2 = 0,
  R_R3 = 0,
  R_R4 = 0,
  R_R5 = 0,
  R_R6 = 0,
  R_R7 = 0,
  R_COND = 0,
  R_COUNT = 0,

}

/* OP Code */
enum
{
   OP_BRANCH = 0,   /* branch */
   OP_ADD,          /* add  */
   OP_LOAD,         /* load */
   OP_STORE,        /* store */
   OP_JUMP,         /* jump register */
   OP_AND,          /* bitwise and */
   OP_LOADR,        /* load register */
   OP_STORER,       /* load register */
   OP_UNUNSED,      /* unused */
   OP_NOT,          /* bitwise not */
   OP_LOADI,        /* load indirect */
   OP_STOREI,       /* store indirect */
   OP_JUMP,         /* jump */
   OP_RESERVED,     /* reserved (unused) */
   OP_LOADEA,       /* load effective address */
   OP_TRAP          /* execute trap */
};




uint16_t registers[R_COUNT];


int main()

{
  printf("Run!");

  return 0;
}
