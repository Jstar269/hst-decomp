/* HSTMATCH module=EBOOT.BIN start=0x00127a68 end=0x00127ac0 symbol=FUN_00127a68 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the member argument Ghidra dropped from the call restored, the float prototype given, and the comma condition split into nested ifs; readability pass; exact match verified; names and types await human review. */
#include "hst/motion_obj.h"

extern void FUN_0005f110(void *obj, float value);

/* Pass value to the linked object and optionally remember it. */
void FUN_00127a68(MotionObj *self,int value,int remember)
{
  if (self->unk50 != 0) {
    FUN_0005f110(self->unk50, (float)value);
    if (remember != 0) {
      self->unk198 = value;
    }
  }
}
