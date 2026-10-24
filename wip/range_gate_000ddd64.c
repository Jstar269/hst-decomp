/* HSTMATCH module=EBOOT.BIN start=0x000ddd64 end=0x000ddf10 symbol=FUN_000ddd64 lang=c99 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
extern float fabsf(float);
#define ABS(x) fabsf(x)

extern int DAT_003386b0;
extern int DAT_003402a0;
extern float DAT_002d279c;

undefined4 FUN_000ddd64(int param_1, float *param_2, int param_3)
{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  float fVar4;

  fVar4 = *(float *)(*(int *)(DAT_003386b0 + 0x88) + 0x110);
  if (ABS(param_2[1] + fVar4) > 0.005f) {
    return 0;
  }
  fVar4 = DAT_002d279c * fVar4;
  if ((*(unsigned char *)(param_1 + 0x45) == '\0') && (param_3 == 0)) {
    fVar1 = 5.4863997f;
  }
  else {
    fVar1 = 4.1148f;
  }
  fVar1 = fVar1 + fVar4;
  if (param_3 == 0) {
    if (fVar1 < ABS(*param_2)) {
      return 0;
    }
  }
  else if (0 < *(int *)(param_1 + 0x58)) {
    if (fVar4 + *(float *)(DAT_003402a0 + 0x1420) * 0.5f < *param_2) {
      return 0;
    }
    if (*param_2 < -fVar1) {
      return 0;
    }
  }
  else {
    if (*param_2 < -(fVar4 + *(float *)(DAT_003402a0 + 0x1420) * 0.5f)) {
      return 0;
    }
    if (fVar1 < *param_2) {
      return 0;
    }
  }
  fVar1 = param_2[2];
  if (fVar1 <= 0.0f) {
    uVar3 = 0;
  }
  else {
    if (param_3 == 0) {
      fVar2 = 11.887199f;
    }
    else {
      fVar2 = 6.4007998f;
    }
    if (fVar2 + fVar4 < fVar1) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
  }
  return uVar3;
}
// NEAR (107/107 words, 84 differ). Logic + literal bit patterns are right (5.4864f must be written
// 5.4863997f, 11.8872f as 11.887199f, 6.4007998f): 0x40af9096/0x413e31f8/0x40ccd35a. The remaining
// delta is the `(c45 == 0 && param_3 == 0) ? 5.4864f : 4.1148f` constant select: retail shares ONE
// 4.1148 materialisation (0xdddc4 lui / 0xdddc8 ori, both conditions branch INTO it) and puts the
// 5.4864 block out of line behind a plain `b`; every spelling tried (if/else, `f = 4.1148f` default
// plus an overriding if) duplicates the else block or loses a word, shifting the whole tail by 8.
// fabsf must come from `extern float fabsf(float);` (MWCC intrinsic -> abs.s); the ABS macro is a
// branch and costs 4 words here. The compare must be written value-first (`fabsf(..) > 0.005f`) to
// get retail's c.ngt.s + bc1tl rather than c.lt.s + bc1fl.
// near miss from lane fm8 (unreviewed)
