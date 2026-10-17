/* HSTMATCH module=hstp_trans_main.prx start=0x000a9da8 end=0x000a9ec0 symbol=FUN_000a9da8 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
// Check difference between two entries against threshold bounds

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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern undefined DAT_003ea460;
extern undefined4 DAT_003ea5c4;
extern undefined4 DAT_003ea5c8;
extern float DAT_003ea5d4;
extern float DAT_003ea5dc;
extern float FUN_0016e74c();

int FUN_000a9da8(undefined4 param_1,int param_2,int param_3,undefined4 param_4)
{
  float scale = 1.0f;
  float fVar3;
  float fVar2;
  
  fVar3 = *(float *)(param_2 + 8) - *(float *)(param_3 + 8);
  fVar2 = (float)FUN_0016e74c(&DAT_003ea460,param_4) * 0.01f;
  if (DAT_003ea5dc * 0.01f + (DAT_003ea5d4 * 0.01f * (float)DAT_003ea5c4 - -fVar2) * scale < fVar3) {
    return 0;
  }
  fVar2 = (float)FUN_0016e74c(&DAT_003ea460,param_4) * 0.01f;
  return (DAT_003ea5dc * 0.01f + (DAT_003ea5d4 * 0.01f * (float)DAT_003ea5c8 - fVar2) * scale > fVar3) ^ 1;
}
