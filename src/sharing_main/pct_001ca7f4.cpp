/* HSTMATCH module=hstp_trans_main.prx start=0x001ca7f4 end=0x001ca890 symbol=FUN_001ca7f4 lang=c++ */
/* Clone of src/eboot/pct_001bca0c.cpp (hstclone.py tag c155507): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: inlined float clamp helper with the upper bound test spelled !(v > hi) so MWCC emits c.ngt.s/bc1tl; exact match verified; names and types await human review. */
extern float DAT_00391988;
extern float DAT_0039198c;

static inline float Clamp(float v, const float &lo, const float &hi)
{
  return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" float FUN_001ca7f4(int param_1)
{
  int y = 0;
  int x = 0;
  y += *(int *)(param_1 + 0x28);
  x += *(int *)(param_1 + 0x2c);
  if (x != 0) {
    return Clamp(100.0f * (float)y / (float)x, DAT_00391988, DAT_0039198c);
  }
  return 0.0f;
}
