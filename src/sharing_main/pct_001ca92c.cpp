/* HSTMATCH module=hstp_trans_main.prx start=0x001ca92c end=0x001ca9c8 symbol=FUN_001ca92c lang=c++ */
/* Clone of src/eboot/pct_001bcb44.cpp (hstclone.py tag c155507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Third member of the pct_001bca0c family: ratio from the object's fields at +0x38/+0x3c, bounds in
   DAT_00391998/DAT_0039199c.  Same inlined clamp, same zeroed `y +=`/`x +=` accumulators. */
extern float DAT_00391998;
extern float DAT_0039199c;

static inline float Clamp(float v, const float &lo, const float &hi)
{
  return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" float FUN_001ca92c(int param_1)
{
  int y = 0;
  int x = 0;
  y += *(int *)(param_1 + 0x38);
  x += *(int *)(param_1 + 0x3c);
  if (x != 0) {
    return Clamp(100.0f * (float)y / (float)x, DAT_00391998, DAT_0039199c);
  }
  return 0.0f;
}
