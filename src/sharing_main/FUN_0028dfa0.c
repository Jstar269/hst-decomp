/* HSTMATCH module=hstp_trans_main.prx start=0x0028dfa0 end=0x0028dfe4 symbol=FUN_0028dfa0 lang=c99 */
/* Clone of src/eboot/FUN_0027cc30.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b2f00;
extern u32 * FUN_0001ec44();

typedef struct ZeroedObj {
  const void *vtable; /* 0x00 */
  char pad04[0x3c - 4];
  u32 unk3c; /* 0x3c */
  u32 unk40; /* 0x40 */
  u32 unk44; /* 0x44 */
  u32 unk48; /* 0x48 */
} ZeroedObj;

/* Constructor: base constructor, class vtable, four fields cleared. */
ZeroedObj * FUN_0028dfa0(ZeroedObj *self)
{
  FUN_0001ec44();
  self->vtable = &DAT_003b2f00;
  self->unk3c = 0;
  self->unk40 = 0;
  self->unk48 = 0;
  self->unk44 = 0;
  return self;
}
