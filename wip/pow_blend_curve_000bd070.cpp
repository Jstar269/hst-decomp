/* HSTMATCH module=hstp_trans_main.prx start=0x000bd070 end=0x000bd220 symbol=FUN_000bd070 lang=c++ */
extern "C" {
extern volatile float DAT_0037b32c;
extern float DAT_0037b330;
extern float DAT_0037b334;
extern float DAT_0037b338;
extern float DAT_0037b33c;
extern float DAT_0037b340;
extern float DAT_0037b344;
extern float FUN_0000ce54(float a, float b);
}

static inline float Clamp(const float &value, const float &lo, const float &hi)
{
  return value < lo ? lo : (!(value > hi) ? value : hi);
}

extern "C" float FUN_000bd070(float x)
{
  float s = DAT_0037b32c;
  float t = 1.0f - s;
  float c = Clamp(x, DAT_0037b330, DAT_0037b334);
  if (c <= s) {
    float a = FUN_0000ce54(c, 2.0f);
    float b = FUN_0000ce54(s, 2.0f);
    float r = Clamp(a / b, DAT_0037b338, DAT_0037b33c);
    return DAT_0037b32c * r;
  } else {
    float a = FUN_0000ce54(t - (c - DAT_0037b32c), 2.0f);
    float b = FUN_0000ce54(t, 2.0f);
    float r = Clamp(1.0f - a / b, DAT_0037b340, DAT_0037b344);
    return DAT_0037b32c + t * r;
  }
}
// near miss (3 words of 108): everything matches except the prologue schedule: retail stores f21, loads
// DAT_0037b32c into f21 (lui/lwc1) and only then stores f20; ours stores f20 immediately after f21.
// Matched so far: inline const-reference Clamp (value<lo?lo:(!(value>hi)?value:hi)) with the doubled lo load;
// `float s = DAT_0037b32c; float t = 1.0f - s;` as the first two statements; pow(c,2.0f)/pow(s,2.0f).
// Retail reloads DAT_0037b32c in the three later reads (no CSE with the f21 copy even without an
// intervening call): only `extern volatile float DAT_0037b32c` reproduced that (an inline getter was CSE'd).
// Ruled out: statement order of c/s/t, const locals, declare-then-assign, `t -= s`, inline helper for 1.0f-v,
// separate volatile read for t (adds a load).
