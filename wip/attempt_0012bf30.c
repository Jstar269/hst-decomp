/* HSTMATCH module=EBOOT.BIN start=0x0012bf30 end=0x0012c1c4 symbol=FUN_0012bf30 lang=c++ */
#pragma opt_strength_reduction on
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined * DAT_002cfc8c;
extern const volatile float DAT_002da9d4;
extern const volatile float DAT_002da9d8;
extern const volatile float DAT_002da9dc;
extern const volatile float DAT_002da9e0;
extern const volatile float DAT_002da9e4;
extern const volatile float DAT_002da9e8;
extern const volatile float DAT_002da9ec;
extern const volatile float DAT_002da9f0;
extern int DAT_0033b574;
extern "C" int FUN_0012d76c(void);

extern "C" int FUN_0012bf30(float *param_1, float *param_2, int param_3)
{
  float *out = param_1;
  float *in = param_2;
  int mode = param_3;
  int enabled = DAT_0033b574;
  float fVar3;
  float fVar4;
  
  if (enabled != 0 && FUN_0012d76c() != 0) {
    *out = 0.0f;
    *in = 0.0f;
    return 0;
  }
  *out = -*(float *)(DAT_002cfc8c + 0x94);
  *in = -*(float *)(DAT_002cfc8c + 0x90);
  if (mode == 0) return 1;
  if (((int)*(char *)(DAT_002cfc8c + 0x89) << 0x1e) >> 0x1e == 1) {
    fVar4 = DAT_002da9d4;
    fVar3 = *in + 1.0f;
    if (fVar3 < DAT_002da9d4) {
      *out = fVar4;
    } else {
      fVar4 = DAT_002da9d8;
      if (fVar3 <= DAT_002da9d8) fVar4 = fVar3;
      *out = fVar4;
    }
  }
  if (((int)*(char *)(DAT_002cfc8c + 0x89) << 0x1a) >> 0x1e == 1) {
    fVar4 = DAT_002da9dc;
    fVar3 = *in - 1.0f;
    if (fVar3 < DAT_002da9dc) {
      *out = fVar4;
    } else {
      fVar4 = DAT_002da9e0;
      if (fVar3 <= DAT_002da9e0) fVar4 = fVar3;
      *out = fVar4;
    }
  }
  if (((int)*(char *)(DAT_002cfc8c + 0x89) << 0x18) >> 0x1e == 1) {
    fVar4 = DAT_002da9e4;
    fVar3 = *in + 1.0f;
    if (fVar3 < DAT_002da9e4) {
      *in = fVar4;
    } else {
      fVar4 = DAT_002da9e8;
      if (fVar3 <= DAT_002da9e8) fVar4 = fVar3;
      *in = fVar4;
    }
  }
  if (((int)*(char *)(DAT_002cfc8c + 0x89) << 0x1c) >> 0x1e != 1) return 1;
  fVar4 = DAT_002da9ec;
  fVar3 = *in - 1.0f;
  if (fVar3 < DAT_002da9ec) {
    *in = fVar4;
  } else {
    fVar4 = DAT_002da9f0;
    if (fVar3 <= DAT_002da9f0) fVar4 = fVar3;
    *in = fVar4;
  }
  return 1;
}
// near miss from lane km4 (unreviewed)
