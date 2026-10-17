/* HSTMATCH module=EBOOT.BIN start=0x0018b2bc end=0x0018b3d4 symbol=FUN_0018b2bc lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2/v0) corrected by hand: reconstructed the const-reference clamp and comparison shape; exact match verified; names and types await human review. */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern "C" {
extern float DAT_002e0bb0;
extern float DAT_002e0bb4;
extern char DAT_002e0b44[];
extern float FUN_0000ce3c(float param_1,float param_2);
extern void FUN_00103480(int);
extern int FUN_001039d8(int, byte *, int);
extern void FUN_0018aa0c(int, int);
}

static inline float Clamp(const float &value, const float &lo, const float &hi)
{
  return value < lo ? lo : (!(value > hi) ? value : hi);
}

extern "C" void FUN_0018b2bc(int param_1)
{
  int iVar1;
  float fVar2;
  float fVar3;
  
  *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
  fVar2 = FUN_0000ce3c(3.0f - (float)*(int *)(param_1 + 0x58),2.0f);
  fVar3 = FUN_0000ce3c(3.0f,2.0f);
  fVar2 = fVar2 / fVar3;
  fVar3 = Clamp(fVar2,DAT_002e0bb0,DAT_002e0bb4);
  iVar1 = FUN_001039d8(param_1,(byte *)DAT_002e0b44,0);
  *(float *)(iVar1 + 100) = -(1.0f - fVar3) * 8.0f;
  *(float *)(iVar1 + 0x78) = fVar3;
  FUN_00103480(param_1);
  if (*(int *)(param_1 + 0x58) < 3) {
  }
  else {
    FUN_0018aa0c(param_1,4);
  }
  return;
}
