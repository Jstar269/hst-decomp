/* HSTMATCH module=EBOOT.BIN start=0x001bc060 end=0x001bc128 symbol=FUN_001bc060 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern float DAT_002e9d70;
extern float DAT_002e9d74;
extern float DAT_002e9d78;
extern float DAT_002e9d7c;

static inline float Clamp(const float &v, const float &lo, const float &hi)
{
  return v < lo ? lo : (!(v > hi) ? v : hi);
}

/* Ratio num/den clamped (0 when den is 0), then scaled to a percentage and clamped again. */
extern "C" float FUN_001bc060(int num, int den)
{
  float ratio = 0.0f;
  if (den != 0) {
    ratio = Clamp((float)num / (float)den, DAT_002e9d70, DAT_002e9d74);
  }
  return Clamp(ratio * 100.0f, DAT_002e9d78, DAT_002e9d7c);
}
