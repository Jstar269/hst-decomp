/* HSTMATCH module=hstp_trans_main.prx start=0x001141f0 end=0x0011429c symbol=FUN_001141f0 lang=c99 */
/* Clone of src/eboot/FUN_0010dc48.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002cc260;
extern u8 DAT_003b0a68;
extern u8 DAT_003b1104;
extern u32 FUN_00056cac();
extern u32 * FUN_001016c0();
extern u32 * FUN_00101748();
extern u32 * FUN_001017dc();

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

MatrixPair * FUN_001141f0(MatrixPair *self,u32 arg)
{
  FUN_001017dc(self);
  FUN_00056cac(self->matrixA);
  self->vtable = (unsigned int)(&DAT_003b0a68);
  self->unk70 = 0;
  self->unk74 = -1;
  self->unk78 = 1.0f;
  self->unk7c = 1.0f;
  FUN_00056cac(self->matrixB);
  self->unkc0 = arg;
  FUN_00101748(self,&DAT_002cc260);
  FUN_001016c0(self->matrixB,&DAT_002cc260);
  self->vtable = (unsigned int)(&DAT_003b1104);
  self->unkd0 = 0;
  self->unkd4 = 0;
  self->unkd8 = 0;
  self->unkdc = 0;
  self->unke0 = 0;
  return self;
}
