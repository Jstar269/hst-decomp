/* HSTMATCH module=EBOOT.BIN start=0x001b2cd0 end=0x001b2d88 symbol=FUN_001b2cd0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: matched the status return type and branch polarity; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001b0ef8();
extern int FUN_0022c988();

void FUN_001b2cd0(int *param_1,u32 param_2)
{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  FUN_001b0ef8(iVar2,1,0,param_2,0);
  if (FUN_0022c988(8) != 0) {
    FUN_001b0ef8(iVar2,0xaf,0,0,0);
    *(u32 *)(iVar2 + 0x7cc) = 0xaf;
  }
  else {
    FUN_001b0ef8(iVar2,0xae,0,0,0);
    *(u32 *)(iVar2 + 0x7cc) = 0xae;
  }
  FUN_001b0ef8(iVar2,0x3e,0,0,0);
  FUN_001b0ef8(iVar2,0x53,0,0,0);
}
