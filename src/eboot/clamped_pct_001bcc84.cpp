/* HSTMATCH module=EBOOT.BIN start=0x001bcc84 end=0x001bcd64 symbol=FUN_001bcc84 lang=c++ */
/* Hand-written reconstruction from the disassembly (EBOOT twin of src/sharing_main/clamped_pct_001caa6c.cpp: ratio of the fields at +0x44/+0x48 clamped to [DAT_002e9d70, DAT_002e9d74], 0.0f when the divisor is 0, then 100 * ratio clamped to [DAT_002e9d78, DAT_002e9d7c]; matching idiom: the two zero-initialised `+=` accumulators of the src/eboot/pct_001bca0c.cpp family keep retail's `move aN,zero; addu`; the clamps are the const-reference Clamp of 0x113580); exact match verified; names and types await human review. */
struct Obj {
  char pad0[0x44];
  int f44;
  int f48;
};
extern float DAT_002e9d70;
extern float DAT_002e9d74;
extern float DAT_002e9d78;
extern float DAT_002e9d7c;

static inline float Clamp(const float &v, const float &lo, const float &hi)
{
  return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" float FUN_001bcc84(Obj *o)
{
  int n = 0;
  int d = 0;
  n += o->f44;
  d += o->f48;
  float r = 0.0f;
  if (d != 0)
    r = Clamp((float)n / (float)d, DAT_002e9d70, DAT_002e9d74);
  return Clamp(100.0f * r, DAT_002e9d78, DAT_002e9d7c);
}
