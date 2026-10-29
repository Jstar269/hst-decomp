/* HSTMATCH module=hstp_trans_main.prx start=0x001017dc end=0x0010181c symbol=FUN_001017dc lang=c99 */
/* Clone of src/eboot/FUN_000fc0a0.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0e38;

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
LimitObj * FUN_001017dc(LimitObj *self)
{
  self->vtable = (unsigned int)(&DAT_003b0e38);
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
