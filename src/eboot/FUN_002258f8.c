/* HSTMATCH module=EBOOT.BIN start=0x002258f8 end=0x00225990 symbol=FUN_002258f8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_parts.h"

extern u8 DAT_00309608;
extern u32 DAT_0034a2e0;
extern u32 DAT_0034a820;
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern int * FUN_00225288();
extern void FUN_00291cdc();

/* Deleting destructor: drop the global instance pointer, delete the part set, then the base. */
ModeObj * FUN_002258f8(ModeObj *self,short delete_flag)
{
  if (self != (ModeObj *)0x0) {
    self->vtbl = &DAT_00309608;
    DAT_0034a2e0 = 0;
    if (self->parts != (ModeParts *)0x0) {
      FUN_00225288(self->parts,1);
      self->parts = 0;
    }
    if (DAT_0034a820 != 0) {
      FUN_00291cdc(DAT_0034a820);
    }
    FUN_0001f0f0(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
