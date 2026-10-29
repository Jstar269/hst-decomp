/* HSTMATCH module=EBOOT.BIN start=0x00266ba4 end=0x00266c48 symbol=FUN_00266ba4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* Object whose destructor tears down two sub-objects that live inside the member block at 0x80. */
typedef struct HeldObj {
  const void *vtable;      /* 0x00 */
  char pad04[0x80 - 4];
  char block80[0xf0 - 0x80]; /* 0x80, member block */
  char subf0[0x14];        /* 0xf0, destroyed by FUN_000e88e4 */
  char sub104[0x0c];       /* 0x104, destroyed by FUN_000e88e4 */
} HeldObj;

extern u8 DAT_00309afc;
extern void FUN_00000a00();
extern int * FUN_000e88e4();
extern u32 * FUN_0028686c();

/* Destructor: releases the two sub-objects, runs the base destructor and frees the object when flag > 0. */
HeldObj * FUN_00266ba4(HeldObj *self,short flag)
{
  void *sub;
  
  if (self != (HeldObj *)0x0) {
    self->vtable = &DAT_00309afc;
    if ((char *)self + 0x80 != (char *)0) {
      sub = self->sub104;
      if ((sub != 0) && (sub != 0)) {
        FUN_000e88e4(sub,0);
      }
      sub = self->subf0;
      if ((sub != 0) && (sub != 0)) {
        FUN_000e88e4(sub,0);
      }
    }
    FUN_0028686c(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
