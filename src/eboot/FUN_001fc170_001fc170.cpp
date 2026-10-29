/* HSTMATCH module=EBOOT.BIN start=0x001fc170 end=0x001fc220 symbol=FUN_001fc170 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5/v17c) corrected by hand: declared the loop index before the cursor to match saved-register allocation; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_00309550;
extern void FUN_00000a00(...);
extern u32 * FUN_00102ea4(...);
}
struct VC_0 { virtual ~VC_0(); };

#define OWNED_COUNT 3  /* owned objects held in a row from +0x80 */

/* Destructor: delete the three owned objects, run the base destructor, free the object when deleteFlag is positive. */
extern "C" u32 * FUN_001fc170(u32 *self,short deleteFlag)
{
  VC_0 *owned;
  int i;
  u32 *cursor;
  
  if (self != (u32 *)0x0) {
    *self = (unsigned int)(&DAT_00309550);
    i = 0;
    cursor = self;
    do {
      owned = (VC_0 *)cursor[0x20];
      if (owned != (VC_0 *)0x0) {
        delete owned;
        cursor[0x20] = 0;
      }
      i = i + 1;
      cursor = cursor + 1;
    } while (i < OWNED_COUNT);
    FUN_00102ea4(self,0);
    if (0 < deleteFlag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
