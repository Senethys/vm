/* Includes  */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/termios.h>
#include <sys/mman.h>

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
  R_COUNT = 0

}

/* OP Codes */
enum
{
    OP_BR = 0, /* branch */
    OP_ADD,    /* add  */
    OP_LD,     /* load */
    OP_ST,     /* store */
    OP_JSR,    /* jump register */
    OP_AND,    /* bitwise and */
    OP_LDR,    /* load register */
    OP_STR,    /* store register */
    OP_RTI,    /* unused */
    OP_NOT,    /* bitwise not */
    OP_LDI,    /* load indirect */
    OP_STI,    /* store indirect */
    OP_JMP,    /* jump */
    OP_RES,    /* reserved (unused) */
    OP_LEA,    /* load effective address */
    OP_TRAP    /* execute trap */
};


/* 655 36 addressable units */
/* Unsigned shory */
/* UINT16_MAX- This is the maximum value that an unsigned 16-bit integer can contain */
uint16_t main_memory[UINT16_MAX]
uint16_t registers[R_COUNT];


/* Condition flags Flags */
enum
{
    FL_POS = 1 << 0, /* Positive */
    FL_ZRO = 1 << 1, /* Zero */
    FL_NEG = 1 << 2, /* Negative */
};


int main(int argc, const char* argv[]) {

  /* set the PC to starting position */
  /* 0x3000 is the default aka " " */
  enum {PC_START = 0x3000};
  registers[R_PC] = PC_START;

  int running = 1;
  while(running) {

    /* FETCH */
    /* Read the me */
    uint16_t instruction = mem_read(registers[R_PC]++);

    /* Why is this bit shiftet right 12 bits */
    uint16_t op = instruction >> 12;

    switch (op)
       {
           case OP_ADD:
               {ADD, 6}
               break;
           case OP_AND:
               {AND, 7}
               break;
           case OP_NOT:
               {NOT, 7}
               break;
           case OP_BR:
               {BR, 7}
               break;
           case OP_JMP:
               {JMP, 7}
               break;
           case OP_JSR:
               {JSR, 7}
               break;
           case OP_LD:
               {LD, 7}
               break;
           case OP_LDI:
               {LDI, 6}
               break;
           case OP_LDR:
               {LDR, 7}
               break;
           case OP_LEA:
               {LEA, 7}
               break;
           case OP_ST:
               {ST, 7}
               break;
           case OP_STI:
               {STI, 7}
               break;
           case OP_STR:
               {STR, 7}
               break;
           case OP_TRAP:
               {TRAP, 8}
               break;
           case OP_RES:
           case OP_RTI:
           default:
               {BAD OPCODE, 7}
               break;
       }


  }

  printf("Run!");

  return 0;
}
