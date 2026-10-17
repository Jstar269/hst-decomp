/* HSTMATCH module=EBOOT.BIN start=0x0018abec end=0x0018ad0c symbol=FUN_0018abec lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: const-reference clamp as in 0x18b2bc, the blend weight kept in a local (1.0f - clamped), second store of (1.0f - w) * 8.0f; exact match verified; names and types await human review. */
typedef unsigned char byte;

extern "C" {
extern float DAT_002e0b78;
extern float DAT_002e0b7c;
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

extern "C" void FUN_0018abec(int param_1)
{
  int iVar1;
  float fVar2;
  float fVar3;
  float w;
  
  *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
  fVar2 = FUN_0000ce3c(3.0f - (float)*(int *)(param_1 + 0x58),2.0f);
  fVar3 = FUN_0000ce3c(3.0f,2.0f);
  fVar2 = fVar2 / fVar3;
  fVar3 = Clamp(fVar2,DAT_002e0b78,DAT_002e0b7c);
  w = 1.0f - fVar3;
  iVar1 = FUN_001039d8(param_1,(byte *)DAT_002e0b44,0);
  *(float *)(iVar1 + 100) = (1.0f - w) * 8.0f;
  *(float *)(iVar1 + 0x78) = w;
  FUN_00103480(param_1);
  if (*(int *)(param_1 + 0x58) < 3) {
  }
  else {
    FUN_0018aa0c(param_1,1);
  }
  return;
}
