/* HSTMATCH module=EBOOT.BIN start=0x001e5f50 end=0x001e5fbc symbol=FUN_001e5f50 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/result_scene.h"

extern void FUN_00103628();
extern void FUN_001e2694();
extern void FUN_001e6224();

/* Free the owned objects and the part at 0x1958, then continue with the caller's three values. */
void FUN_001e5f50(ResultScene *self,u32 arg1,u32 arg2,int arg3)
{
  FUN_001e2694(self);
  FUN_00103628(self->part1958,0);
  FUN_001e6224(self,arg1,arg2,arg3,'\0');
}
