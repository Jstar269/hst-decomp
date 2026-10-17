/* HSTMATCH module=hstp_trans_main.prx start=0x00197a08 end=0x00197b20 symbol=FUN_00197a08 lang=c++ */
/* Clone of src/eboot/advance_blend_0018b2bc.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
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
extern float DAT_00388230;
extern float DAT_00388234;
extern char DAT_003881c4[];
extern float FUN_0000ce54(float param_1,float param_2);
extern void FUN_00108dac(int);
extern int FUN_00109304(int, byte *, int);
extern void FUN_00197158(int, int);
}

static inline float Clamp(const float &value, const float &lo, const float &hi)
{
  return value < lo ? lo : (!(value > hi) ? value : hi);
}

extern "C" void FUN_00197a08(int param_1)
{
  int iVar1;
  float fVar2;
  float fVar3;
  
  *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
  fVar2 = FUN_0000ce54(3.0f - (float)*(int *)(param_1 + 0x58),2.0f);
  fVar3 = FUN_0000ce54(3.0f,2.0f);
  fVar2 = fVar2 / fVar3;
  fVar3 = Clamp(fVar2,DAT_00388230,DAT_00388234);
  iVar1 = FUN_00109304(param_1,(byte *)DAT_003881c4,0);
  *(float *)(iVar1 + 100) = -(1.0f - fVar3) * 8.0f;
  *(float *)(iVar1 + 0x78) = fVar3;
  FUN_00108dac(param_1);
  if (*(int *)(param_1 + 0x58) < 3) {
  }
  else {
    FUN_00197158(param_1,4);
  }
  return;
}
