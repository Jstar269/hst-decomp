/* HSTMATCH module=hstp_trans_main.prx start=0x00277b20 end=0x00277bc4 symbol=FUN_00277b20 lang=c99 */
/* Clone of src/eboot/FUN_00266ba4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Object whose destructor tears down two sub-objects that live inside the member block at 0x80. */
typedef struct HeldObj {
  const void *vtable;      /* 0x00 */
  char pad04[0x80 - 4];
  char block80[0xf0 - 0x80]; /* 0x80, member block */
  char subf0[0x14];        /* 0xf0, destroyed by FUN_000ed9b8 */
  char sub104[0x0c];       /* 0x104, destroyed by FUN_000ed9b8 */
} HeldObj;

extern u8 DAT_003b2de4;
extern void FUN_00000a00();
extern int * FUN_000ed9b8();
extern u32 * FUN_00297f98();

/* Destructor: releases the two sub-objects, runs the base destructor and frees the object when flag > 0. */
HeldObj * FUN_00277b20(HeldObj *self,short flag)
{
  void *sub;
  
  if (self != (HeldObj *)0x0) {
    self->vtable = &DAT_003b2de4;
    if ((char *)self + 0x80 != (char *)0) {
      sub = self->sub104;
      if ((sub != 0) && (sub != 0)) {
        FUN_000ed9b8(sub,0);
      }
      sub = self->subf0;
      if ((sub != 0) && (sub != 0)) {
        FUN_000ed9b8(sub,0);
      }
    }
    FUN_00297f98(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
