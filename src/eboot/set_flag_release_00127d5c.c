/* HSTMATCH module=EBOOT.BIN start=0x00127d5c end=0x00127dc4 symbol=FUN_00127d5c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: flag and parameter as unsigned char (lbu/andi), float first argument 0.0f (mtc1 zero) with the pointer in a0 (prototype void(float, void *)); readability pass; exact match verified; names and types await human review. */
#include "hst/motion_obj.h"

extern void FUN_0005f110(float, void *);

/* Change the flag; when it turns off with no stored value, reset the linked object. */
void FUN_00127d5c(MotionObj *self, unsigned char flag)
{
  if (flag != self->flag339) {
    self->flag339 = flag;
    self->unk33c = 0;
    if (((self->flag339 == 0) && (self->unk198 == 0)) &&
       (self->unk50 != 0)) {
      FUN_0005f110(0.0f, self->unk50);
      self->unk198 = 0;
    }
  }
}
