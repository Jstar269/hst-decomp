/* HSTMATCH module=EBOOT.BIN start=0x001fe080 end=0x001fe0dc symbol=FUN_001fe080 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_002cfc8c;
extern bool FUN_0001ea64();

u8 FUN_001fe080(u32 param_1,u32 param_2,u32 param_3)
{
  u8 uVar1;
  
  uVar1 = FUN_0001ea64(DAT_002cfc8c,param_1,param_2,2,9);
  if ((*(u32 *)(DAT_002cfc8c + 0x80) & param_3) != 0) {
    uVar1 = 0;
  }
  return uVar1;
}
