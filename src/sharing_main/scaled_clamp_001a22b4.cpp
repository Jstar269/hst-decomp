/* HSTMATCH module=hstp_trans_main.prx start=0x001a22b4 end=0x001a23a4 symbol=FUN_001a22b4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" float DAT_00388cd4;
extern "C" float DAT_00388cd8;

struct Obj {
  char pad[12];
  unsigned char b12;
};

static inline float Clamp(const float &v, const float &lo, const float &hi)
{
  return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" float FUN_001a22b4(Obj *o, float p, float q)
{
  if (o != 0) {
    float base;
    if (o->b12 == 40) {
      base = 160.0f;
    } else {
      base = (float)(o->b12 / 5 * 10 + 130);
    }
    float d = base - p;
    float r = d * q + 1.0;
    return Clamp(r, DAT_00388cd4, DAT_00388cd8);
  }
  return 1.0f;
}
