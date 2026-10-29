/* HSTMATCH module=EBOOT.BIN start=0x00060fb0 end=0x0006107c symbol=FUN_00060fb0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified (the same shape should also match the hstp_trans_main.prx twin 0x00061e34: Vec4 with a user memberwise copy ctor, an inline Op(Vec4 a, const Vec4 &b) that passes &a/&b to the out-of-line helper and returns the result by value); names and types await human review. */
struct Vec4 {
  float x, y, z, w;
  Vec4() {}
  Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
};

struct Obj {
  char pad0[64];
  Vec4 v40;
  char pad1[16];
  Vec4 v60;
};

extern "C" void FUN_00022418(Vec4 *out, const Vec4 *a, const Vec4 *b);

static inline Vec4 Op(Vec4 a, const Vec4 &b)
{
  Vec4 r;
  FUN_00022418(&r, &a, &b);
  return r;
}

extern "C" void FUN_00060fb0(Obj *self, const Vec4 *b)
{
  self->v40 = Op(self->v40, *b);
  self->v60 = Op(self->v60, *b);
}
