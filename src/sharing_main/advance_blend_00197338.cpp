/* HSTMATCH module=hstp_trans_main.prx start=0x00197338 end=0x00197458 symbol=FUN_00197338 lang=c++ */
/* Clone of src/eboot/advance_blend_0018abec.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: const-reference clamp as in 0x18b2bc, the blend weight kept in a local (1.0f - clamped), second store of (1.0f - w) * 8.0f; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern float DAT_003881f8;
extern float DAT_003881fc;
extern char DAT_003881c4[];
extern float FUN_0000ce54(float param_1,float param_2);
extern void FUN_00108dac(int);
extern int FUN_00109304(int, u8 *, int);
extern void FUN_00197158(int, int);
}

static inline float Clamp(const float &value, const float &lo, const float &hi)
{
  return value < lo ? lo : (!(value > hi) ? value : hi);
}

extern "C" void FUN_00197338(int param_1)
{
  int iVar1;
  float fVar2;
  float fVar3;
  float w;
  
  *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
  fVar2 = FUN_0000ce54(3.0f - (float)*(int *)(param_1 + 0x58),2.0f);
  fVar3 = FUN_0000ce54(3.0f,2.0f);
  fVar2 = fVar2 / fVar3;
  fVar3 = Clamp(fVar2,DAT_003881f8,DAT_003881fc);
  w = 1.0f - fVar3;
  iVar1 = FUN_00109304(param_1,(u8 *)DAT_003881c4,0);
  *(float *)(iVar1 + 100) = (1.0f - w) * 8.0f;
  *(float *)(iVar1 + 0x78) = w;
  FUN_00108dac(param_1);
  if (*(int *)(param_1 + 0x58) < 3) {
  }
  else {
    FUN_00197158(param_1,1);
  }
}
