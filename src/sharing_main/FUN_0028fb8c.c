/* HSTMATCH module=hstp_trans_main.prx start=0x0028fb8c end=0x0028fc14 symbol=FUN_0028fb8c lang=c99 */
/* Clone of src/eboot/FUN_0027e748.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/dtor_pair_obj.h"

extern u8 DAT_003b2f64;
extern void FUN_00000a00();
extern int * FUN_000550a0();
extern int * FUN_00290840();

/* Deleting destructor: sets the vtable, destroys both sub-objects, frees the object when delete_flag > 0. */
DtorPairObj * FUN_0028fb8c(DtorPairObj *self,short delete_flag)
{
  int *sub;
  
  if (self != (DtorPairObj *)0x0) {
    sub = &self->unk10;
    self->vtable = &DAT_003b2f64;
    if ((sub != (int *)0x0) && (sub != (int *)0x0)) {
      FUN_000550a0(sub,0);
    }
    sub = &self->unk4;
    if ((sub != (int *)0x0) && (sub != (int *)0x0)) {
      FUN_00290840(sub,0);
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
