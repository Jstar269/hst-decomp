/* HSTMATCH module=hstp_trans_main.prx start=0x00170b24 end=0x00170bc4 symbol=FUN_00170b24 lang=c++ */
/* Clone of src/eboot/clamp_ratio_001646a0.cpp (hstclone.py tag om2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
// Matching idiom: the ratio must be an IN-PLACE divide of a variable that already holds
// the numerator (`float f = t - first; f = f / (last - first);`). The one-expression
// spelling `(t - first) / (last - first)` puts the numerator in the dead call-result FPR
// and swaps $f2/$f3 (4 words off).
struct TrackCtx { float *samples; int count; };
extern TrackCtx *DAT_003ea850;
extern float DAT_00387944;
extern float DAT_00387948;
extern "C" float FUN_00170038();

static inline float Clamp(float v, const float &lo, const float &hi)
{
  return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" float FUN_00170b24()
{
  float t = FUN_00170038();
  TrackCtx *ctx = DAT_003ea850;
  float *p = ctx->samples;
  float first = p[0];
  int n = ctx->count - 1;
  float last = p[n * 5];
  float f = t - first;
  f = f / (last - first);
  return Clamp(f, DAT_00387944, DAT_00387948);
}
