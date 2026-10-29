/* HSTMATCH module=EBOOT.BIN start=0x00280114 end=0x00280188 symbol=FUN_00280114 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u32 DAT_0034a7f0;
extern void FUN_00000a00(...);
}
struct VC_0 { virtual ~VC_0(); };

/* Deleting destructor of a holder: deletes the owned object (first word), clears the global
   instance pointer and frees the holder itself when delete_flag > 0. */
extern "C" int * FUN_00280114(int *self,short delete_flag)
{
  int *owned;

  if (self != (int *)0x0) {
    owned = (int *)*self;
    if (owned != (int *)0x0) {
      delete ((VC_0 *)(owned));
      *self = 0;
    }
    DAT_0034a7f0 = 0;
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
