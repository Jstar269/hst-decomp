/* HSTMATCH module=EBOOT.BIN start=0x0010dc48 end=0x0010dcf4 symbol=FUN_0010dc48 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag q1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002bc410;
extern u8 DAT_0030779c;
extern u8 DAT_00307e38;
extern u32 FUN_00056098();
extern u32 * FUN_000fbf84();
extern u32 * FUN_000fc00c();
extern u32 * FUN_000fc0a0();

/* Object on a base with a 0x30-byte header, followed by two 4x4 matrices. */
typedef struct MatrixPair {
  u32 vtable;          /* 0x00 */
  char base[0x2c];     /* 0x04 set up by the base constructor */
  char matrixA[0x40];  /* 0x30 */
  u32 unk70;           /* 0x70 */
  int unk74;           /* 0x74 */
  float unk78;         /* 0x78 */
  float unk7c;         /* 0x7c */
  char matrixB[0x40];  /* 0x80 */
  u32 unkc0;           /* 0xc0 constructor argument */
  char padc4[0xc];
  u32 unkd0;           /* 0xd0 */
  u32 unkd4;           /* 0xd4 */
  u32 unkd8;           /* 0xd8 */
  u32 unkdc;           /* 0xdc */
  u32 unke0;           /* 0xe0 */
} MatrixPair;

MatrixPair * FUN_0010dc48(MatrixPair *self,u32 arg)
{
  FUN_000fc0a0(self);
  FUN_00056098(self->matrixA);
  self->vtable = (unsigned int)(&DAT_0030779c);
  self->unk70 = 0;
  self->unk74 = -1;
  self->unk78 = 1.0f;
  self->unk7c = 1.0f;
  FUN_00056098(self->matrixB);
  self->unkc0 = arg;
  FUN_000fc00c(self,&DAT_002bc410);
  FUN_000fbf84(self->matrixB,&DAT_002bc410);
  self->vtable = (unsigned int)(&DAT_00307e38);
  self->unkd0 = 0;
  self->unkd4 = 0;
  self->unkd8 = 0;
  self->unkdc = 0;
  self->unke0 = 0;
  return self;
}
