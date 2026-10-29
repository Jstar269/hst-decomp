/* HSTMATCH module=EBOOT.BIN start=0x00063b20 end=0x00063c14 symbol=FUN_00063b20 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/*
  The object pointer is a type-converted local (`RampObj *self = (RampObj *)selfAddr;`), which defers its
  callee-saved copy to after the parameter copies; with the parameters declared int,int,float (EABI gives the
  floats their own registers, so this is register-identical to int,float,int) the prologue copies come out
  `move s1,a1; mov.s $f20,$f12; move s0,a0` exactly as retail.
*/
#include "hst/types.h"
#include "hst/ramp_obj.h"
extern int FUN_00063a0c(void);
extern void FUN_00063554(RampVec4 *, RampObj *);
extern RampVec4 FUN_0004c644(const RampVec4 *);
extern void FUN_000513a0(void *, int);

/* Sets up the ramp with a transformed start value, white end value and the given duration. */
void FUN_00063b20(int selfAddr, int frames, float value)
{
  RampObj *self = (RampObj *)selfAddr;
  RampVec4 transformed;
  RampVec4 identity;
  RampVec4 input;
  RampVec4 *source;
  identity.x = 1.0f;
  identity.y = 1.0f;
  identity.z = 1.0f;
  identity.w = 0.0f;
  if (FUN_00063a0c() != 0) {
    source = &identity;
  } else {
    FUN_00063554(&input, self);
    source = &input;
  }
  transformed = FUN_0004c644(source);
  self->from.x = transformed.x;
  self->from.y = transformed.y;
  self->from.z = transformed.z;
  self->from.w = transformed.w;
  self->to.x = 1.0f;
  self->to.y = 1.0f;
  self->to.z = 1.0f;
  self->to.w = 1.0f;
  self->duration = (float)frames;
  self->remaining = (float)frames;
  self->unk10 = -1.0f;
  FUN_000513a0(self->handle, 0);
  self->unk40 = 0;
  self->unk41 = 0;
  self->limit = RAMP_DEFAULT_LIMIT;
  self->unk50 = 0;
  self->unk51 = 0;
  self->unk52 = 1;
  self->unk53 = 0;
  self->unk54 = value;
}
