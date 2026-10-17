/* HSTMATCH module=EBOOT.BIN start=0x000a73e0 end=0x000a74f8 symbol=FUN_000a73e0 lang=c99 */
/* Clone of src/sharing_main/check_diff_bounds_000a9da8.c (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_00341120;
extern undefined4 DAT_00341284;
extern undefined4 DAT_00341288;
extern float DAT_00341294;
extern float DAT_0034129c;
extern float FUN_001621c0();

int FUN_000a73e0(undefined4 param_1,int param_2,int param_3,undefined4 param_4)
{
  float scale = 1.0f;
  float fVar3;
  float fVar2;
  
  fVar3 = *(float *)(param_2 + 8) - *(float *)(param_3 + 8);
  fVar2 = (float)FUN_001621c0(&DAT_00341120,param_4) * 0.01f;
  if (DAT_0034129c * 0.01f + (DAT_00341294 * 0.01f * (float)DAT_00341284 - -fVar2) * scale < fVar3) {
    return 0;
  }
  fVar2 = (float)FUN_001621c0(&DAT_00341120,param_4) * 0.01f;
  return (DAT_0034129c * 0.01f + (DAT_00341294 * 0.01f * (float)DAT_00341288 - fVar2) * scale > fVar3) ^ 1;
}
