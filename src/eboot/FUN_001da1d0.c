/* HSTMATCH module=EBOOT.BIN start=0x001da1d0 end=0x001da278 symbol=FUN_001da1d0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

#define FLOAT_ONE_BITS 0x3f800000   /* bit pattern of 1.0f */

typedef struct Obj {
  u32 vtable;       /* 0x00 */
  char pad04[0x3c - 4];
  u32 unk3c;        /* 0x3c */
  u32 unk40;        /* 0x40 */
  char pad44[0x90 - 0x44];
  u32 vec90[4];     /* 0x90, set to (0, 0, 0, 1.0f) */
  u32 veca0[4];     /* 0xa0, set to (0, 0, 0, 1.0f) */
  u32 vecb0[4];     /* 0xb0, set to (0, 0, 0, 1.0f) */
  u32 unkc0;        /* 0xc0 */
  u8 flagc4;        /* 0xc4, set to 1 */
  char padc5[3];
  u32 unkc8;        /* 0xc8 */
  u8 flagcc;        /* 0xcc, set to 1 */
  u8 flagcd;        /* 0xcd */
  char padce[2];
  u32 vecd0[4];     /* 0xd0, set to (0, 0, 0, 1.0f) */
  u32 vece0[4];     /* 0xe0, cleared */
} Obj;

extern u8 DAT_00309408;
extern u32 * FUN_0001f06c();

/* Constructor: base constructor, vtable, then reset the flags and the four position-like quads. */
Obj * FUN_001da1d0(Obj *self)
{
  FUN_0001f06c();
  self->vtable = (unsigned int)(&DAT_00309408);
  self->unk3c = 0;
  self->unk40 = 0;
  self->unkc0 = 0;
  self->flagc4 = 1;
  self->unkc8 = 0;
  self->flagcc = 1;
  self->flagcd = 0;
  self->vec90[0] = 0;
  self->vec90[1] = 0;
  self->vec90[2] = 0;
  self->vec90[3] = FLOAT_ONE_BITS;
  self->veca0[0] = 0;
  self->veca0[1] = 0;
  self->veca0[2] = 0;
  self->veca0[3] = FLOAT_ONE_BITS;
  self->vecb0[0] = 0;
  self->vecb0[1] = 0;
  self->vecb0[2] = 0;
  self->vecb0[3] = FLOAT_ONE_BITS;
  self->vecd0[0] = 0;
  self->vecd0[1] = 0;
  self->vecd0[2] = 0;
  self->vecd0[3] = FLOAT_ONE_BITS;
  self->vece0[0] = 0;
  self->vece0[1] = 0;
  self->vece0[2] = 0;
  self->vece0[3] = 0;
  return self;
}
