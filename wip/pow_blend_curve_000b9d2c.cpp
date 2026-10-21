/* HSTMATCH module=EBOOT.BIN start=0x000b9d2c end=0x000b9edc symbol=FUN_000b9d2c lang=c++ */
extern "C" {
extern volatile float DAT_002d4a64;
extern float DAT_002d4a68;
extern float DAT_002d4a6c;
extern float DAT_002d4a70;
extern float DAT_002d4a74;
extern float DAT_002d4a78;
extern float DAT_002d4a7c;
extern float FUN_0000ce3c(float a, float b);
}

static inline float Clamp(const float &value, const float &lo, const float &hi)
{
  return value < lo ? lo : (!(value > hi) ? value : hi);
}

extern "C" float FUN_000b9d2c(float x)
{
  float s = DAT_002d4a64;
  float t = 1.0f - s;
  float c = Clamp(x, DAT_002d4a68, DAT_002d4a6c);
  if (c <= s) {
    float a = FUN_0000ce3c(c, 2.0f);
    float b = FUN_0000ce3c(s, 2.0f);
    float r = Clamp(a / b, DAT_002d4a70, DAT_002d4a74);
    return DAT_002d4a64 * r;
  } else {
    float a = FUN_0000ce3c(t - (c - DAT_002d4a64), 2.0f);
    float b = FUN_0000ce3c(t, 2.0f);
    float r = Clamp(1.0f - a / b, DAT_002d4a78, DAT_002d4a7c);
    return DAT_002d4a64 + t * r;
  }
}
// NEAR MISS (3 words of 108), copied from the Sharing twin wip/pow_blend_curve_000bd070.cpp (same code, addresses mapped).
// Only the prologue schedule differs: retail stores f21, loads DAT_002d4a64 into f21 (lui/lwc1) and only then stores f20;
// ours stores f20 immediately after f21 (3 words 0xb9d38..0xb9d40).
// Retail reloads DAT_002d4a64 in the three later reads (no CSE with the f21 copy): only `extern volatile float` reproduces that.
// Ruled out here: non-volatile first read with volatile-cast later reads (schedule unchanged, plus 2 commutative operand swaps),
// t declared inside the else branch / after the Clamp (66 words), the earlier twin attempts (statement order, const locals,
// declare-then-assign, t -= s, inline 1.0f-v helper).
// near miss from lane sn4 (unreviewed)
