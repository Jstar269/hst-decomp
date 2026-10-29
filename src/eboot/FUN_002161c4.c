/* HSTMATCH module=EBOOT.BIN start=0x002161c4 end=0x00216208 symbol=FUN_002161c4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/target_obj.h"

extern u32 DAT_0034a150;
extern void FUN_00000a00();

/* Destructor: clear the global that FUN_00216174 set, and free the object when `flag` is positive. */
TargetObj * FUN_002161c4(TargetObj *self,short flag)
{
  if ((self != 0) && (DAT_0034a150 = 0, 0 < flag)) {
    FUN_00000a00();
  }
  return self;
}
