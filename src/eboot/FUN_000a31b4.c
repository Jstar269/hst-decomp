/* HSTMATCH module=EBOOT.BIN start=0x000a31b4 end=0x000a31fc symbol=FUN_000a31b4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_000b3c68();
extern float FUN_00163e60();

float FUN_000a31b4(int param_1)
{
  u32 uVar1;
  float fVar2;
  
  uVar1 = FUN_000b3c68();
  fVar2 = (float)FUN_00163e60(uVar1,*(u32 *)(param_1 + 0x154));
  return (fVar2 - 1.0f) / 9.0f;
}
