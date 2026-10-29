/* HSTMATCH module=EBOOT.BIN start=0x000634a0 end=0x00063554 symbol=FUN_000634a0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/*
  Matching idiom: the pointer/integer parameters are declared before the floats. EABI gives int and float
  parameters independent registers, so the mapping is unchanged, but the prologue copies are emitted in
  declaration order, which is the retail order (`move s0,t0` before `mov.s $f20,$f13`).
*/
#include "hst/ramp_obj.h"

extern void FUN_000513a0();

/* Sets up the ramp: copies the start and end values, sets duration and remaining, handle mode, flag and limit. */
void FUN_000634a0(RampObj *obj, float *from, float *to, unsigned mode, unsigned char flag,
                  float duration, float limit)
{
  obj->from.x = from[0];
  obj->from.y = from[1];
  obj->from.z = from[2];
  obj->from.w = from[3];
  obj->to.x = to[0];
  obj->to.y = to[1];
  obj->to.z = to[2];
  obj->to.w = to[3];
  obj->duration = duration;
  obj->remaining = duration;
  obj->unk10 = -1.0f;
  FUN_000513a0(obj->handle, mode);
  obj->unk40 = flag;
  obj->unk41 = 0;
  if (limit < 0.0f) {
    limit = RAMP_DEFAULT_LIMIT;
  }
  obj->limit = limit;
  return;
}
