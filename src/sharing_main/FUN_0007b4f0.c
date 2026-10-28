/* HSTMATCH module=hstp_trans_main.prx start=0x0007b4f0 end=0x0007b504 symbol=FUN_0007b4f0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1gs); exact match verified; names and types await human review. */
#include "hst/types.h"

u8 FUN_0007b4f0(int param_1)
{
  u8 uVar1;
  
  uVar1 = **(u8 **)(param_1 + 0x48);
  *(u8 **)(param_1 + 0x48) = *(u8 **)(param_1 + 0x48) + 1;
  return uVar1;
}
