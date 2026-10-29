/* HSTMATCH module=hstp_trans_main.prx start=0x00061e34 end=0x00061f00 symbol=FUN_00061e34 lang=c++ */
/* Hand-written reconstruction from the disassembly (twin of EBOOT 0x00060fb0, same source with the other helper address); exact match verified; names and types await human review. */
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

extern "C" void FUN_00022440(Vec4 *out, const Vec4 *a, const Vec4 *b);

static inline Vec4 Op(Vec4 a, const Vec4 &b)
{
  Vec4 r;
  FUN_00022440(&r, &a, &b);
  return r;
}

extern "C" void FUN_00061e34(Obj *self, const Vec4 *b)
{
  self->v40 = Op(self->v40, *b);
  self->v60 = Op(self->v60, *b);
}
