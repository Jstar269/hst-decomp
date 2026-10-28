/* HSTMATCH module=EBOOT.BIN start=0x00281128 end=0x00281238 symbol=FUN_00281128 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003415a8;
extern u32 * FUN_000149a8();
extern void FUN_0008d148();
extern u32 * FUN_0008d388();
extern int FUN_000d7e30();
extern u64 FUN_001bc630(float param_1);
extern u16 * FUN_00259a1c();
extern void FUN_00281238();

void FUN_00281128(int param_1)
{
  float fVar1;
  u64 uVar2;
  u32 auStack_c8 [50];
  u32 auStack_190 [50];
  u32 auStack_258 [50];
  
  FUN_00281238((u32 *)(param_1 + 0x4e8));
  FUN_0008d148((u8 *)(param_1 + 0x890));
  FUN_0008d388(auStack_c8,0,0,0,0,0,0);
  FUN_00259a1c((u16 *)(param_1 + 0x528),(u16 *)auStack_c8);
  FUN_000d7e30((int)auStack_c8,-1);
  FUN_0008d388(auStack_190,0,0,0,0,0,0);
  FUN_00259a1c((u16 *)(param_1 + 0x648),(u16 *)auStack_190);
  FUN_000d7e30((int)auStack_190,-1);
  FUN_0008d388(auStack_258,0,0,0,0,0,0);
  FUN_00259a1c((u16 *)(param_1 + 0x768),(u16 *)auStack_258);
  FUN_000d7e30((int)auStack_258,-1);
  FUN_000149a8((u32 *)(param_1 + 0x5f4),(u32 *)(DAT_003415a8 + 0x20));
  fVar1 = *(float *)(DAT_003415a8 + 0x1414);
  uVar2 = FUN_001bc630(fVar1);
  *(char *)(param_1 + 0x628) = (char)uVar2;
  *(float *)(param_1 + 0x624) = fVar1;
}
