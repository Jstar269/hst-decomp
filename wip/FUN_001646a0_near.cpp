/* HSTMATCH module=EBOOT.BIN start=0x001646a0 end=0x00164740 symbol=FUN_001646a0 lang=c++ */
// NEAR MISS (40/40 words, 4 differ at +0x44): only the FPR colours of `last` and the
// numerator differ. Ours: last=$f3, sub=$f2; retail: last=$f2, sub=$f3 (the `div.s`
// operands follow). Everything else - the call, the ctx loads, the (count-1)*20 index,
// the `lwc1 $f4` first element, the early `lwc1 $f1` lo load and the whole clamp tail
// (`c.lt.s/bc1f; lwc1 f0,lo; b` + `c.ngt.s/bc1tl; mov.s`) - is exact.
// Ruled out (all 4 words off, same colours): ratio as a local or inline; num/den/span
// locals in either order; last declared before first; `p[0]` read twice inline; the
// division moved into an inline Ratio(t, first, last) helper; the (count-1) folded form
// `p[(ctx->count - 1) * 5]` (39 words, worse) and `p[ctx->count * 5 - 5]`.
struct TrackCtx { float *samples; int count; };
extern TrackCtx *DAT_00341510;
extern float DAT_002e0388;
extern float DAT_002e038c;
extern "C" float FUN_00163aac();

static inline float Clamp(float v, const float &lo, const float &hi)
{
  return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" float FUN_001646a0()
{
  float t = FUN_00163aac();
  TrackCtx *ctx = DAT_00341510;
  float *p = ctx->samples;
  float first = p[0];
  int n = ctx->count - 1;
  float last = p[n * 5];
  return Clamp((t - first) / (last - first), DAT_002e0388, DAT_002e038c);
}
// near miss from lane ds4 (unreviewed)
