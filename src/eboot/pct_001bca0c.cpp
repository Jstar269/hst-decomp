/* HSTMATCH module=EBOOT.BIN start=0x001bca0c end=0x001bcaa8 symbol=FUN_001bca0c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: inlined float clamp helper with the upper bound test spelled !(v > hi) so MWCC emits c.ngt.s/bc1tl; exact match verified; names and types await human review. */
extern float DAT_002e9d50;
extern float DAT_002e9d54;

static inline float Clamp(float v, const float &lo, const float &hi)
{
  return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" float FUN_001bca0c(int param_1)
{
  int y = 0;
  int x = 0;
  y += *(int *)(param_1 + 0x28);
  x += *(int *)(param_1 + 0x2c);
  if (x != 0) {
    return Clamp(100.0f * (float)y / (float)x, DAT_002e9d50, DAT_002e9d54);
  }
  return 0.0f;
}
