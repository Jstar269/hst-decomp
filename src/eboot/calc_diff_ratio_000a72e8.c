/* HSTMATCH module=EBOOT.BIN start=0x000a72e8 end=0x000a73e0 symbol=FUN_000a72e8 lang=c99 */
/* Clone of src/sharing_main/calc_diff_ratio_000a9cb0.c (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
// Compute scaled relative difference ratio between two entries

typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern float DAT_0034129c;
extern int FUN_000b3c68(int);
extern float FUN_001640d0(int, undefined4, undefined4);
extern float FUN_00164290(int, undefined4);

float FUN_000a72e8(int param_1,int param_2,int param_3,undefined4 param_4)
{
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar3 = FUN_001640d0(FUN_000b3c68(param_1), *(undefined4 *)(param_1 + 0x154), param_4) * 0.01f;
  fVar4 = FUN_00164290(FUN_000b3c68(param_1), *(undefined4 *)(param_1 + 0x154)) * 0.01f;
  fVar6 = *(float *)(param_2 + 8);
  fVar6 -= *(float *)(param_3 + 8) + DAT_0034129c * 0.01f;
  fVar5 = fVar6 / fVar3;
  if ((int)fVar5 != 0) {
    float sign = (float)((fVar6 < 0.0f) ? -1 : 1);
    float step = -fVar3 + fVar4;
    fVar5 = (fVar6 + step * sign) / fVar4;
  }
  return fVar5;
}
