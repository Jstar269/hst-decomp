/* HSTMATCH module=EBOOT.BIN start=0x0023c2ac end=0x0023c338 symbol=FUN_0023c2ac lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: the +0x1750 access is a member of param_1, the two vtable calls are real C++ virtuals (slot 0x10) on two view structs, the two float stores re-read the param_1+0x14c0 member (no CSE) and keep the destination pointer in a0; readability pass; exact match verified; names and types await human review. */
#include "hst/range_screen.h"

extern "C" void FUN_002174bc(void *);
extern "C" void FUN_00102c54(void);
struct V { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); };
struct W { virtual void w0(); virtual void w1(); virtual void w2(); virtual void w3(); };

/* Calls virtual slot 2 on the optional object and on the member at 4, then copies two values of the record
   into the float block (record int 0x14 as a float, the sum of record ints 0x18 and 0x1c as a float). */
extern "C" void FUN_0023c2ac(RangeScreen *self)
{
  V *opt = (V *)self->unk1750;
  W *obj;
  float *out;
  if (opt != 0) opt->v2();
  obj = (W *)self->unk04;
  obj->w2();
  FUN_002174bc(self->rec);
  out = self->unk20;
  out[0x18] = (float)self->rec->unk14;
  out[0x19] = (float)(self->rec->unk18 + self->rec->unk1c);
  FUN_00102c54();
}
