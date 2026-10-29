/* HSTMATCH module=EBOOT.BIN start=0x000fc0a0 end=0x000fc0e0 symbol=FUN_000fc0a0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00307b6c;

#define LIMIT_DEFAULT 100000.0f

typedef struct LimitObj {
  u32 vtable;           /* 0x00 */
  u32 unk04;
  u32 unk08;
  u32 unk0c;
  u32 unk10;
  u32 unk14;
  u32 unk18;
  u8 unk1c;
  char pad1d[3];
  float limit;          /* 0x20 */
  u8 unk24;
} LimitObj;

/* Constructor: zeroes the fields and sets the default limit. */
LimitObj * FUN_000fc0a0(LimitObj *self)
{
  self->vtable = (unsigned int)(&DAT_00307b6c);
  self->unk04 = 0;
  self->unk08 = 0;
  self->unk0c = 0;
  self->unk10 = 0;
  self->unk14 = 0;
  self->unk18 = 0;
  self->unk1c = 0;
  self->limit = LIMIT_DEFAULT;
  self->unk24 = 0;
  return self;
}
