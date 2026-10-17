/* HSTMATCH module=hstp_trans_main.prx start=0x001c9e48 end=0x001c9f10 symbol=FUN_001c9e48 lang=c++ */
/* Clone of src/eboot/ratio_percent_clamp_001bc060.cpp (hstclone.py tag s10170158a1r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern float DAT_003919a8;
extern float DAT_003919ac;
extern float DAT_003919b0;
extern float DAT_003919b4;

static inline float Clamp(const float &v, const float &lo, const float &hi)
{
  return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" float FUN_001c9e48(int num, int den)
{
  float ratio = 0.0f;
  if (den != 0) {
    ratio = Clamp((float)num / (float)den, DAT_003919a8, DAT_003919ac);
  }
  return Clamp(ratio * 100.0f, DAT_003919b0, DAT_003919b4);
}
