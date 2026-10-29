/* HSTMATCH module=EBOOT.BIN start=0x001ce280 end=0x001ce318 symbol=FUN_001ce280 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/range_obj.h"

extern "C" float fabsf(float);

struct Vec4 { float x, y, z, w; };

struct VC {
  virtual void s0();
  virtual void s1();
  virtual void s2();
  virtual void s3();
  virtual void s4();
  virtual void s5();
  virtual void *s6();
};

extern float DAT_002ea2e4;
extern float DAT_002ea2e8;
extern "C" void FUN_00022434(Vec4 *out, const void *a, const void *b);

/* Return 1 when the position difference to `other` is inside the horizontal range and its vertical offset is inside the height limit. */
extern "C" int FUN_001ce280(RangeObj *self, VC *other)
{
  Vec4 d;
  int r;
  FUN_00022434(&d, &self->pos, other->s6());
  float y = d.y;
  if (d.x * d.x + d.z * d.z < DAT_002ea2e4 * DAT_002ea2e4) {
    if (fabsf(y) < DAT_002ea2e8) {
      r = 1;
    } else {
      r = 0;
    }
  } else {
    r = 0;
  }
  return r;
}
