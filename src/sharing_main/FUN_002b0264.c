/* HSTMATCH module=hstp_trans_main.prx start=0x002b0264 end=0x002b0294 symbol=FUN_002b0264 lang=c99 */
/* Clone of src/eboot/FUN_002a0e58.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct LimitedObj {
  u32 vtable;       /* 0x0 */
  u8 unk4;          /* 0x4 */
  char pad5[0x104 - 0x5];
  u32 unk104;       /* 0x104 */
  u32 limit;        /* 0x108 */
  u8 unk10c;        /* 0x10c */
} LimitedObj;

extern u8 DAT_002dc598;

LimitedObj * FUN_002b0264(LimitedObj *self)
{
  self->vtable = (unsigned int)(&DAT_002dc598);
  self->unk4 = 0;
  self->unk104 = 0;
  self->limit = 0;
  self->unk10c = 0;
  self->limit = 0x7fffffff;
  return self;
}
