/* HSTMATCH module=EBOOT.BIN start=0x00203dcc end=0x00204110 symbol=FUN_00203dcc lang=c99 */
typedef unsigned char undefined;
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef struct { float m[16]; } M4;

extern float DAT_002bc410;
extern float DAT_002bc414;
extern float DAT_002bc418;
extern float DAT_002bc41c;
extern float DAT_002bc420;
extern float DAT_002bc424;
extern float DAT_002bc428;
extern float DAT_002bc42c;
extern float DAT_002bc430;
extern float DAT_002bc434;
extern float DAT_002bc438;
extern float DAT_002bc43c;
extern float DAT_002bc440;
extern float DAT_002bc444;
extern float DAT_002bc448;
extern float DAT_002bc44c;
extern int DAT_002ef1d8;
extern M4 DAT_0032b1d0;
extern float FUN_0000ce3c(float, float);
extern void FUN_000224b8(float, float *, int);
extern void FUN_00022418(float *, float *, int);
extern void FUN_00022548(float *, float *, float *);
extern void FUN_00022570(float *, float *, float *);
extern void FUN_00202cb8(float, int, int, int, float *);
extern void FUN_002033a8(float, int, int, int, float *);
extern void FUN_00203680(float, int, int, int, float *);

void FUN_00203dcc(int param_1, int param_2, int param_3)
{
  float m1[16];
  M4 m2;
  float m3[4];
  float out[16];
  float res[4];
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;

  m1[0] = DAT_002bc410;
  iVar2 = param_2 * 0x10;
  m1[1] = DAT_002bc414;
  m1[2] = DAT_002bc418;
  m1[3] = DAT_002bc41c;
  m1[4] = DAT_002bc420;
  m1[5] = DAT_002bc424;
  m1[6] = DAT_002bc428;
  m1[7] = DAT_002bc42c;
  m1[8] = DAT_002bc430;
  m1[9] = DAT_002bc434;
  m1[10] = DAT_002bc438;
  m1[11] = DAT_002bc43c;
  m1[12] = DAT_002bc440;
  m1[13] = DAT_002bc444;
  m1[14] = DAT_002bc448;
  m1[15] = DAT_002bc44c;
  FUN_000224b8(*(float *)(iVar2 + param_1 + 0x1c), &m1[12],
               param_1 + 0x4f0);
  FUN_00022418(&m1[12], &m1[12], param_1 + 0x500);
  m3[0] = 0.0f;
  m3[1] = 0.0f;
  m3[2] = 0.0f;
  m1[15] = 1.0f;
  m3[3] = 1.0f;
  m2 = DAT_0032b1d0;
  fVar4 = *(float *)(iVar2 + param_1 + 0x24) *
          (1.0f - (1.0f - *(float *)(param_1 + 0x510)) * *(float *)(iVar2 + param_1 + 0x1c));
  FUN_00022570(out, m2.m, m1);
  FUN_00022548(res, out, m3);
  res[0] = res[0] / res[3];
  res[1] = res[1] / res[3];
  if (*(int *)(iVar2 + param_1 + 0x20) == 6) {
    if (param_3 == 0) {
      iVar1 = *(int *)(param_1 + 0x518) + *(int *)(param_1 + 0x51c);
      if (iVar1 < 0) {
        iVar1 = iVar1 + 1;
      }
      FUN_00202cb8(((fVar4 * *(float *)(param_1 + 0x388)) / *(float *)(iVar2 + param_1 + 0x24)) /
                     2.0f,
                   param_1, param_2, iVar1 >> 1, res);
    }
    else {
      iVar2 = *(int *)(param_1 + 0x518) + *(int *)(param_1 + 0x51c);
      if (iVar2 < 0) {
        iVar2 = iVar2 + 1;
      }
      FUN_002033a8(fVar4, param_1, param_2, iVar2 >> 1, res);
    }
  }
  else {
    iVar2 = DAT_002ef1d8;
    if (*(int *)(param_1 + 0x51c) <= DAT_002ef1d8) {
      iVar2 = *(int *)(param_1 + 0x51c);
    }
    fVar3 = FUN_0000ce3c((float)iVar2 / 68.0f, 0.5f);
    FUN_00203680(fVar4, param_1, param_2, (int)(fVar3 * 128.0f), res);
  }
  return;
}

// NEAR MISS 0x00203dcc: 185/209 words, first diff at +0x24 (one extra saved
// FPR: ours keeps f20 AND f21, retail only f20).
// What now matches: frame 0x110, saved ra/s0-s4 + one FPR, the 16-float
// matrix at sp+0xd0 copied element-by-element from the 16 separate scalar
// globals DAT_002bc410..DAT_002bc44c (retail uses one `lui` per element, so
// those really are 16 independent symbol references), the vec4 at sp+0xc0
// (0,0,0,1) merged with m1[15]=1.0 into one `lui 0x3f80`, and the
// FUN_000224b8/FUN_00022418 pair operating on `&m1[12]` (sp+0x100) followed by
// FUN_00022570/FUN_00022548.
// What is still wrong:
//  * an extra `jal __extendsfdf2` (0x20f5c) that retail does not have: one call
//    argument is being promoted to double, so check the prototypes of
//    FUN_0000ce3c / FUN_00202cb8 / FUN_002033a8 (retail passes those floats in
//    $f12/$f13 and takes ce3c's result back in v0, i.e. soft-float return).
//  * ~24 words short overall: retail's three tail branches are longer, and
//    retail reloads `DAT_002ef1d8` twice in the min-computation
//    (`lw a0,-3624(v0)` + `lw v0,-3624(v0)`) - that is not the plain
//    `iVar2 = DAT; if (field <= DAT) iVar2 = field;` spelling.
//  * retail ends the res[] divide with stores back into res[0]/res[1] and then
//    reloads them (`c7a100b0`), ours keeps them in registers.
// Ruled out: scalar (non-array) locals for the two matrices - mwcc then deletes
// the unread elements; `m2[i] = DAT_0032b1d0[i]` element-wise - folds a `lui`
// per element instead of one base register; a float * pointer walking the
// global - same folding.
// near miss from lane fm10 (unreviewed)
