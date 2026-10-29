/* HSTMATCH module=hstp_trans_main.prx start=0x001e49b8 end=0x001e49e0 symbol=FUN_001e49b8 lang=c99 */
/* Clone of src/eboot/FUN_001d6bc8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b2f7c;
extern u8 DAT_003b2f88;

/* Polymorphic object with two zeroed words; two vtables are installed in turn, the second stays. */
typedef struct VtableWords { const void *vtable; u32 unk04; u32 unk08; } VtableWords;

VtableWords * FUN_001e49b8(VtableWords *self)
{
  self->vtable = &DAT_003b2f88;
  self->unk04 = 0;
  self->unk08 = 0;
  self->vtable = &DAT_003b2f7c;
  return self;
}
