/* HSTMATCH module=EBOOT.BIN start=0x001bcb44 end=0x001bcbe0 symbol=FUN_001bcb44 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Third member of the pct_001bca0c family: ratio from the object's fields at +0x38/+0x3c, bounds in
   DAT_002e9d60/DAT_002e9d64.  Same inlined clamp, same zeroed `y +=`/`x +=` accumulators. */
extern float DAT_002e9d60;
extern float DAT_002e9d64;

static inline float Clamp(float v, const float &lo, const float &hi)
{
  return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" float FUN_001bcb44(int param_1)
{
  int y = 0;
  int x = 0;
  y += *(int *)(param_1 + 0x38);
  x += *(int *)(param_1 + 0x3c);
  if (x != 0) {
    return Clamp(100.0f * (float)y / (float)x, DAT_002e9d60, DAT_002e9d64);
  }
  return 0.0f;
}
