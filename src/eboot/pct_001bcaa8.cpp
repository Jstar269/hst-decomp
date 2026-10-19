/* HSTMATCH module=EBOOT.BIN start=0x001bcaa8 end=0x001bcb44 symbol=FUN_001bcaa8 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Twin of pct_001bca0c.cpp with the ratio taken from the object's fields at +0x30/+0x34 instead of
   the +0x28/+0x2c globals pair; same inlined clamp (upper test spelled !(v > hi) for c.ngt.s/bc1tl)
   and the same `int y = 0; y += ...;` zeroed accumulators that make MWCC emit `move a1,zero;
   move a2,zero; addu`. */
extern float DAT_002e9d58;
extern float DAT_002e9d5c;

static inline float Clamp(float v, const float &lo, const float &hi)
{
  return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" float FUN_001bcaa8(int param_1)
{
  int y = 0;
  int x = 0;
  y += *(int *)(param_1 + 0x30);
  x += *(int *)(param_1 + 0x34);
  if (x != 0) {
    return Clamp(100.0f * (float)y / (float)x, DAT_002e9d58, DAT_002e9d5c);
  }
  return 0.0f;
}
