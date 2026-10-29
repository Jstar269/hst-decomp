/* HSTMATCH module=hstp_trans_main.prx start=0x00291588 end=0x002915fc symbol=FUN_00291588 lang=c++ */
/* Clone of src/eboot/FUN_00280114.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u32 DAT_003f3b20;
extern void FUN_00000a00(...);
}
struct VC_0 { virtual ~VC_0(); };

/* Deleting destructor of a holder: deletes the owned object (first word), clears the global
   instance pointer and frees the holder itself when delete_flag > 0. */
extern "C" int * FUN_00291588(int *self,short delete_flag)
{
  int *owned;

  if (self != (int *)0x0) {
    owned = (int *)*self;
    if (owned != (int *)0x0) {
      delete ((VC_0 *)(owned));
      *self = 0;
    }
    DAT_003f3b20 = 0;
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
