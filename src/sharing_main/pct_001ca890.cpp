/* HSTMATCH module=hstp_trans_main.prx start=0x001ca890 end=0x001ca92c symbol=FUN_001ca890 lang=c++ */
/* Clone of src/eboot/pct_001bcaa8.cpp (hstclone.py tag c155507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Twin of pct_001bca0c.cpp with the ratio taken from the object's fields at +0x30/+0x34 instead of
   the +0x28/+0x2c globals pair; same inlined clamp (upper test spelled !(v > hi) for c.ngt.s/bc1tl)
   and the same `int y = 0; y += ...;` zeroed accumulators that make MWCC emit `move a1,zero;
   move a2,zero; addu`. */
extern float DAT_00391990;
extern float DAT_00391994;

static inline float Clamp(float v, const float &lo, const float &hi)
{
  return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" float FUN_001ca890(int param_1)
{
  int y = 0;
  int x = 0;
  y += *(int *)(param_1 + 0x30);
  x += *(int *)(param_1 + 0x34);
  if (x != 0) {
    return Clamp(100.0f * (float)y / (float)x, DAT_00391990, DAT_00391994);
  }
  return 0.0f;
}
