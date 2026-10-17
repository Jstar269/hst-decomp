/* HSTMATCH module=hstp_trans_main.prx start=0x000a9cb0 end=0x000a9da8 symbol=FUN_000a9cb0 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
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

extern float DAT_003ea5dc;
extern int FUN_000b6e80(int);
extern float FUN_00170860(int, undefined4, undefined4);
extern float FUN_00170910(int, undefined4);

float FUN_000a9cb0(int param_1,int param_2,int param_3,undefined4 param_4)
{
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar3 = FUN_00170860(FUN_000b6e80(param_1), *(undefined4 *)(param_1 + 0x154), param_4) * 0.01f;
  fVar4 = FUN_00170910(FUN_000b6e80(param_1), *(undefined4 *)(param_1 + 0x154)) * 0.01f;
  fVar6 = *(float *)(param_2 + 8);
  fVar6 -= *(float *)(param_3 + 8) + DAT_003ea5dc * 0.01f;
  fVar5 = fVar6 / fVar3;
  if ((int)fVar5 != 0) {
    float sign = (float)((fVar6 < 0.0f) ? -1 : 1);
    float step = -fVar3 + fVar4;
    fVar5 = (fVar6 + step * sign) / fVar4;
  }
  return fVar5;
}
