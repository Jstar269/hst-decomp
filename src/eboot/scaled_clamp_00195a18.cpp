/* HSTMATCH module=EBOOT.BIN start=0x00195a18 end=0x00195b08 symbol=FUN_00195a18 lang=c++ */
/* Clone of src/sharing_main/scaled_clamp_001a22b4.cpp (hstclone.py tag s10170158a1r3e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" float DAT_002e15a8;
extern "C" float DAT_002e15ac;

struct Obj {
  char pad[12];
  unsigned char b12;
};

static inline float Clamp(const float &v, const float &lo, const float &hi)
{
  return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" float FUN_00195a18(Obj *o, float p, float q)
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
    return Clamp(r, DAT_002e15a8, DAT_002e15ac);
  }
  return 1.0f;
}
