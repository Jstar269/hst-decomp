/* HSTMATCH module=EBOOT.BIN start=0x000e56f0 end=0x000e57bc symbol=FUN_000e56f0 lang=c++ */
/* WIP: 31 words differ. Structure/semantics confirmed (flag = (f74 <= 0.0f) then !f61, delete-else-update,
   then the FUN_000224d8/00022e44 radius and the five field stores). Blocker: in C++ MWCC truncates every
   comparison result with `andi v1,v1,0xff`; the SAME source in lang=c99 (probe2.c) emits retail's andi-free
   `bc1t/li 1; move 0; beqz; lbu; sltu; xori` sequence, so the original flag code was C-typed while the
   `delete` needs C++. Also the delete block in retail has an extra outer null test. */
struct Vec4 { float x, y, z, w; };

struct Res {
  virtual ~Res();
  virtual void m1();
  char pad4[0x61 - 4];
  unsigned char f61;
  char pad62[0x74 - 0x62];
  float f74;
  char pad78[0xa0 - 0x78];
  float fa0, fa4, fa8, fac, fb0;
};

struct Obj {
  char pad[0x48];
  Res *f48;
  int f4c;
  float f50, f54, f58, f5c;
  char pad60[0x70 - 0x60];
  Vec4 f70;
};

extern "C" {
float FUN_000224d8(const Vec4 *, const Vec4 *);
float FUN_00022e44(float);
}

extern "C" void FUN_000e56f0(Obj *self)
{
  Res *obj = self->f48;

  if (obj != 0) {
    bool b = obj->f74 <= 0.0f;
    if (b)
      b = !obj->f61;
    if (b) {
      delete obj;
      self->f48 = 0;
    } else {
      float r = FUN_00022e44(FUN_000224d8(&self->f70, &self->f70));
      Res *o = self->f48;
      o->fa0 = self->f50;
      o->fa4 = self->f54;
      o->fa8 = self->f58;
      o->fac = self->f5c;
      o->fb0 = r;
    }
  }
}
// near miss from lane ds6 (unreviewed)
