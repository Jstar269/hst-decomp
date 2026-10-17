/* HSTMATCH module=hstp_trans_main.prx start=0x001dc95c end=0x001dc9f4 symbol=FUN_001dc95c lang=c++ */
/* Clone of src/eboot/range_check_001ce280.cpp (hstclone.py tag s10170158a1r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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

struct Obj { char pad[0x30]; Vec4 pos; };

extern float DAT_00391f3c;
extern float DAT_00391f40;
extern "C" void FUN_0002245c(Vec4 *out, const void *a, const void *b);

extern "C" int FUN_001dc95c(Obj *self, VC *other)
{
  Vec4 d;
  int r;
  FUN_0002245c(&d, &self->pos, other->s6());
  float y = d.y;
  if (d.x * d.x + d.z * d.z < DAT_00391f3c * DAT_00391f3c) {
    if (fabsf(y) < DAT_00391f40) {
      r = 1;
    } else {
      r = 0;
    }
  } else {
    r = 0;
  }
  return r;
}
