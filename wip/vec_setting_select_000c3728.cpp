/* HSTMATCH module=EBOOT.BIN start=0x000c3728 end=0x000c3a1c symbol=FUN_000c3728 lang=c++ */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code();
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern "C" {
extern undefined4 DAT_002d5a8c;
extern float DAT_002ef1e0[];
extern float DAT_002ef1e4[];
extern float DAT_003412e4;
extern float DAT_003412e8;
extern float DAT_003412ec;
extern float DAT_003412f0;
extern float DAT_003412f4;
extern float DAT_003412f8;
extern float FUN_00022418(float *,float *,float *);
extern void FUN_0004d414(void *,void *,void *);
extern int FUN_000c3a1c(void *, void *, float *);
extern float FUN_0000c000(float);
extern float FUN_00049da4(void *);
extern float FUN_00049e68(void *);
extern float FUN_00049ec4(void *);
extern void FUN_00049fbc(void *);
extern void FUN_0004a080(void *);
extern void FUN_0005bc58(void *);
}

typedef struct Result {
  float vec[8];
  undefined4 f20;
  undefined4 f24;
  undefined4 f28;
  undefined4 f2c;
  float ratio;
  undefined4 f34;
  undefined4 f38;
} Result;

static inline float Sel(const float &c0, const float &c1, const float &c2)
{
  float f;
  switch (DAT_002d5a8c) {
  default:
    f = 0.0f;
    break;
  case 1:
    f = c1;
    break;
  case 0:
    f = c0;
    break;
  case 2:
    f = c2;
    break;
  }
  return f;
}

extern "C" bool FUN_000c3728(char *param_1,Result *param_2,float *param_3,float *param_4, undefined4 *param_5,float *param_6,int param_7)
{
  int iVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fSetting;
  float denominator;
  float zero;
  float local_10[4];
  float local_20[4];
  
  *param_5 = 0x3f800000;
  local_20[0] = param_6[0];
  fVar5 = param_6[1];
  local_20[1] = fVar5;
  local_20[2] = param_6[2];
  local_20[3] = param_6[3];
  local_20[3] = FUN_00022418(local_20,local_20,param_6 + 4);
  local_20[3] = 1.0f;
  fVar3 = local_20[1];
  if (param_7 != 0) {
    iVar1 = FUN_000c3a1c(param_1,param_2,param_6);
    if (iVar1 != 0) {
      iVar1 = param_2->f38;
      *param_3 = DAT_002ef1e0[iVar1 * 4];
      *param_4 = DAT_002ef1e4[iVar1 * 4];
    }
  }
  fVar4 = (float)param_6[3];
  if (fVar3 >= -fVar4) {
    denominator = param_6[5];
    fVar3 = denominator != 0.0f ? (-fVar4 - fVar5) / denominator : 0.0f;
    if (fVar3 <= param_2->ratio) {
      param_2->ratio = fVar3;
      param_2->f34 = 0;
      FUN_0004d414(local_10,param_2,param_6);
      param_2->vec[0] = local_10[0];
      param_2->vec[1] = local_10[1];
      param_2->vec[2] = local_10[2];
      param_2->vec[3] = local_10[3];
      param_2->vec[4] = param_2->vec[0];
      param_2->vec[5] = param_2->vec[1];
      param_2->vec[6] = param_2->vec[2];
      param_2->vec[7] = param_2->vec[3];
      ((undefined4 *)param_2)[5] = 0;
      param_2->f20 = 0;
      param_2->f24 = 0xbf800000;
      param_2->f28 = 0;
      param_2->f2c = 0;
      switch (DAT_002d5a8c) {
      default:
        uVar2 = 0;
        break;
      case 1:
        uVar2 = 0xc;
        break;
      case 0:
        uVar2 = 1;
        break;
      case 2:
        uVar2 = 0x22;
        break;
      }
      param_2->f38 = uVar2;
      if (*(int *)(param_1 + 0x1d4) < 1) {
        *param_4 = Sel(DAT_003412f0, DAT_003412e8, DAT_003412f8);
      }
      else {
        *param_4 = Sel(DAT_003412f0, DAT_003412e8, DAT_003412f8);
      }
      *param_3 = Sel(DAT_003412ec, DAT_003412e4, DAT_003412f4);
    }
  }
  return param_2->ratio != 3.4028235e+38f;
}
// sy1: 188/189 words; was 86 differing words. Solved: the three settings selections are `switch (DAT_002d5a8c)` with
// `default: 0.0f` first and cases written 1,0,2 (retail tests 2,0,1; globals read inside the case) via an inline Sel(c0,c1,c2);
// the f38 id switch likewise (default 0, case 1: 0xc, case 0: 1, case 2: 0x22); the ratio division is
// `fVar3 = d != 0.0f ? (-fVar4 - fVar5) / d : 0.0f;` (gives retail's f1/f2 naming and branch).
// Left (2 deltas, both 1 word): (1) retail loads param_6[0] into f0 BEFORE param_6[1] into f20 and both before the two
// `move`s; every source order of those loads puts f20 first or after the moves (tried 8 forms, Vec4 struct copy worse);
// (2) in the SECOND copy of the param_4 selection (the `else` of `*(int*)(p+0x1d4) < 1`) retail emits an extra
// `b +1` after case 2 (case-2 load sits in its delay slot) - all 24 case orders of a direct switch, a float local and
// an inline Sel for that copy were tried, none emits it.
// near miss from lane sy1 (unreviewed)
