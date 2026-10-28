/* HSTMATCH module=EBOOT.BIN start=0x00220238 end=0x00220338 symbol=FUN_00220238 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2/v0) corrected by hand: typed nested float fields and used a const-reference clamp helper; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u32 DAT_002eff90;
extern float DAT_002f0b4c;
extern float DAT_002f0b7c;
extern float DAT_002f0b80;
extern u8 * DAT_003415a8;
extern float DAT_0034a200;
extern float DAT_0034a204;
extern void FUN_000ffb3c(int, int);
extern void FUN_00103480(int);
extern void FUN_00220370(int);
extern u32 FUN_0026f4e4(u8 *);
}

struct Inner_60 {
  char pad00[0x60];
  float f60;
  float f64;
  char pad68[0x10];
  float f78;
};

struct Outer_60 {
  char pad00[0x60];
  struct Inner_60 *inner;
};

static inline float Clamp_20220238(const float &value, const float &low, const float &high)
{
  return value < low ? low : (!(value > high) ? value : high);
}

extern "C" void FUN_00220238(int param_1,u8 param_2)
{
  u32 uVar1;
  int iVar2;
  float fVar3;
  
  uVar1 = FUN_0026f4e4(DAT_003415a8 + 0x80);
  if ((uVar1 & 0xff) == 0) {
    *(u32 *)(param_1 + 0x5c) = DAT_002eff90;
    *(u8 *)(param_1 + 0x74) = param_2;
    FUN_00220370(param_1);
    struct Outer_60 *outer = (struct Outer_60 *)param_1;
    outer->inner->f60 = DAT_0034a200;
    outer->inner->f64 = DAT_0034a204;
    fVar3 = Clamp_20220238(DAT_002f0b4c, DAT_002f0b7c, DAT_002f0b80);
    outer->inner->f78 = fVar3;
    FUN_00103480(param_1);
    FUN_000ffb3c(*(int *)(param_1 + 0x68),*(unsigned char *)(param_1 + 0x74) != 0 ^ 1);
  }
}
