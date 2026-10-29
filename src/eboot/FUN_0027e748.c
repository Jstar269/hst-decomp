/* HSTMATCH module=EBOOT.BIN start=0x0027e748 end=0x0027e7d0 symbol=FUN_0027e748 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/dtor_pair_obj.h"

extern u8 DAT_00309c7c;
extern void FUN_00000a00();
extern int * FUN_00054554();
extern int * FUN_0027f3cc();

/* Deleting destructor: sets the vtable, destroys both sub-objects, frees the object when delete_flag > 0. */
DtorPairObj * FUN_0027e748(DtorPairObj *self,short delete_flag)
{
  int *sub;
  
  if (self != (DtorPairObj *)0x0) {
    sub = &self->unk10;
    self->vtable = &DAT_00309c7c;
    if ((sub != (int *)0x0) && (sub != (int *)0x0)) {
      FUN_00054554(sub,0);
    }
    sub = &self->unk4;
    if ((sub != (int *)0x0) && (sub != (int *)0x0)) {
      FUN_0027f3cc(sub,0);
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
