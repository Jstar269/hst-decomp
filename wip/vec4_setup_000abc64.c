/* HSTMATCH module=EBOOT.BIN start=0x000abc64 end=0x000abdcc symbol=FUN_000abc64 lang=c99 */
typedef unsigned int uint;

extern float DAT_002d46b8;
extern float DAT_002d46bc;
extern float DAT_002d46c0;
extern int DAT_003386b0;
extern void FUN_00022450(float *param_1, float *param_2, int param_3);
extern void FUN_000adb10(int param_1, float *param_2, float *param_3, int param_4);

void FUN_000abc64(float *param_1, int param_2, int param_3, float *param_4,
                  float *param_5)
{
  float fVar1;
  float v[4];

  if (*(float *)(param_2 + 0x580) > 0.0f) {
    fVar1 = -1.0f;
  }
  else {
    fVar1 = 1.0f;
  }
  *param_4 = 0.0f;
  *param_5 = 0.0f;
  if (param_3 == 0) {
    param_3 = *(int *)(param_2 + 0x140);
  }
  FUN_000adb10(param_2, param_4, param_5, param_3);
  v[0] = *param_4 * (1.3716f * DAT_002d46b8) + 2.0574f * fVar1;
  v[1] = -*(float *)(*(int *)(DAT_003386b0 + 0x88) + 0x110);
  v[3] = 1.0f;
  v[2] = *param_5 *
         (0.5f * (DAT_002d46c0 * 6.4007998f - DAT_002d46bc * 6.4007998f)) +
         0.5f * (DAT_002d46bc * 6.4007998f + DAT_002d46c0 * 6.4007998f);
  FUN_00022450(v, v, param_2 + 0x5a0);
  *param_1 = v[0];
  param_1[1] = v[1];
  param_1[2] = v[2];
  param_1[3] = v[3];
}
// near miss (22/90 words): matched so far: c.ngt.s/bc1t from `if (x > 0.0f) f=-1;else f=1;`
// with fVar1 in f20, the float v[4] kept in memory across FUN_00022450 (element reloads
// for the four stores), `*param_4 * (1.3716f * DAT) + 2.0574f * fVar1` (parenthesized
// literal-first product, value-first outer mul), `*param_5 * (0.5f * (c6 - c5)) + 0.5f * (c5 + c6)`,
// and the 6.4007998f literal (6.4008f encodes one ulp off, 0x40ccd35b vs 0x40ccd35a).
// Remaining: MWCC schedules `addiu a0,sp,48` (&v for the final call) after the expression
// instead of retail's hoist right after the DAT load, materialises the 1.0f constant early
// in a3 instead of late in v0, colours the 2.0574/6.4008/0.5f constants a0/v1/a0 instead
// of v1/a3/v1, and loads DAT_002d46c0 before DAT_002d46bc; the cascade reorders ~22 words.
// Ruled out: float[4] vs four named locals (locals keep values in f20/f21 across the call,
// 2 extra FP saves), value-first vs literal-first mul orderings (see above), reordering
// the v[] assignment statements (store order v[0],v[1],v[3],v[2] already matches).
// near miss from lane fb1 (unreviewed)
