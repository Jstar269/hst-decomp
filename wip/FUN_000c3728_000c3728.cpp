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
    fVar3 = 0.0f;
    denominator = param_6[5];
    zero = 0.0f;
    if (zero != denominator) {
      fVar3 = (-fVar4 - fVar5) / denominator;
    }
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
      if (DAT_002d5a8c == 2) {
        uVar2 = 0x22;
      }
      else if (DAT_002d5a8c == 0) {
        uVar2 = 1;
      }
      else if (DAT_002d5a8c == 1) {
        uVar2 = 0xc;
      }
      else {
        uVar2 = 0;
      }
      param_2->f38 = uVar2;
      if (*(int *)(param_1 + 0x1d4) < 1) {
        fSetting = DAT_003412f8;
        if (((DAT_002d5a8c != 2) && (fSetting = DAT_003412f0, DAT_002d5a8c != 0)) &&
           (fSetting = DAT_003412e8, DAT_002d5a8c != 1)) {
          fSetting = 0.0f;
        }
        *param_4 = fSetting;
      }
      else {
        fSetting = DAT_003412f8;
        if (((DAT_002d5a8c != 2) && (fSetting = DAT_003412f0, DAT_002d5a8c != 0)) &&
           (fSetting = DAT_003412e8, DAT_002d5a8c != 1)) {
          fSetting = 0.0f;
        }
        *param_4 = fSetting;
      }
      fSetting = DAT_003412f4;
      if (((DAT_002d5a8c != 2) && (fSetting = DAT_003412ec, DAT_002d5a8c != 0)) &&
         (fSetting = DAT_003412e4, DAT_002d5a8c != 1)) {
        fSetting = 0.0f;
      }
      *param_3 = fSetting;
    }
  }
  return param_2->ratio != 3.4028235e+38f;
}
// Near miss: 86 of 189 words differ, starting in the prologue's parameter and float-load scheduling.
// Ruled out C versus C++ mode, array versus Vec4 local input, const pointer qualifiers, if/switch/ternary code selection, and alternate threshold branch forms.
// near miss from lane km5 (unreviewed)
