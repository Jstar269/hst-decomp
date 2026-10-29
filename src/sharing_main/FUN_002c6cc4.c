/* HSTMATCH module=hstp_trans_main.prx start=0x002c6cc4 end=0x002c6d4c symbol=FUN_002c6cc4 lang=c99 */
/* Clone of src/eboot/FUN_0027e748.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/dtor_pair_obj.h"

extern u8 DAT_003b32bc;
extern void FUN_00000a00();
extern int * FUN_000550a0();
extern int * FUN_002c7184();

/* Deleting destructor: sets the vtable, destroys both sub-objects, frees the object when delete_flag > 0. */
DtorPairObj * FUN_002c6cc4(DtorPairObj *self,short delete_flag)
{
  int *sub;
  
  if (self != (DtorPairObj *)0x0) {
    sub = &self->unk10;
    self->vtable = &DAT_003b32bc;
    if ((sub != (int *)0x0) && (sub != (int *)0x0)) {
      FUN_000550a0(sub,0);
    }
    sub = &self->unk4;
    if ((sub != (int *)0x0) && (sub != (int *)0x0)) {
      FUN_002c7184(sub,0);
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
