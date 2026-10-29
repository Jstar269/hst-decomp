/* HSTMATCH module=EBOOT.BIN start=0x001e54dc end=0x001e5524 symbol=FUN_001e54dc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the first call's receiver argument and the member load at +0x175c; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/result_scene.h"

extern void FUN_00103628();
extern void FUN_001e2694();
extern void FUN_001e5524();

/* Free the owned objects and the part at 0x175c, then continue with the caller's value. */
void FUN_001e54dc(ResultScene *self,u32 arg)
{
  FUN_001e2694(self);
  FUN_00103628(self->part175c,0);
  FUN_001e5524(self,arg);
}
