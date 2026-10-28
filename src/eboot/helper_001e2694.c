/* HSTMATCH module=EBOOT.BIN start=0x001e2694 end=0x001e27a0 symbol=FUN_001e2694 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7/v21) corrected by hand: used the owner-relative field offset +0x175c; readability pass; exact match verified; names and types await human review. */
#include "hst/result_screen.h"

extern void FUN_00103628();
extern void FUN_001e5f00();
extern void FUN_0021e4cc();

/* Free the objects the result screen owns. */
void FUN_001e2694(ResultScreen *self)
{
  void *obj;

  if (self->unk1f4 != 0) {
    FUN_00103628(self->unk1f4,1);
  }
  obj = self->unk9b4;
  if (obj != 0) {
    FUN_00103628(obj,1);
  }
  obj = self->unk810;
  if (obj != 0) {
    FUN_00103628(obj,1);
  }
  obj = self->unk175c;
  if (obj != 0) {
    FUN_00103628(obj,1);
  }
  obj = self->unk1954;
  if (obj != 0) {
    FUN_00103628(obj,1);
  }
  obj = self->unk1d68;
  if (obj != 0) {
    FUN_00103628(obj,1);
  }
  obj = self->unk1958;
  if (obj != 0) {
    FUN_00103628(obj,1);
  }
  obj = self->unk1d64;
  if (obj != 0) {
    FUN_0021e4cc(obj,1,0);
  }
  obj = self->return_lay;
  if (obj != 0) {
    FUN_00103628(obj,1);
  }
  obj = self->exhibition_lay;
  if (obj != 0) {
    FUN_00103628(obj,1);
  }
  FUN_001e5f00(self);
  if (self->overlay_lay != 0) {
    FUN_00103628(self->overlay_lay,1);
  }
}
