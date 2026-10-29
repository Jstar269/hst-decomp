/* HSTMATCH module=EBOOT.BIN start=0x002a0e58 end=0x002a0e88 symbol=FUN_002a0e58 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct LimitedObj {
  u32 vtable;       /* 0x0 */
  u8 unk4;          /* 0x4 */
  char pad5[0x104 - 0x5];
  u32 unk104;       /* 0x104 */
  u32 limit;        /* 0x108 */
  u8 unk10c;        /* 0x10c */
} LimitedObj;

extern u8 DAT_002cc2ac;

LimitedObj * FUN_002a0e58(LimitedObj *self)
{
  self->vtable = (unsigned int)(&DAT_002cc2ac);
  self->unk4 = 0;
  self->unk104 = 0;
  self->limit = 0;
  self->unk10c = 0;
  self->limit = 0x7fffffff;
  return self;
}
