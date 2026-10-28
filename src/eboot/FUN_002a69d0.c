/* HSTMATCH module=EBOOT.BIN start=0x002a69d0 end=0x002a6a40 symbol=FUN_002a69d0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00300af4;
extern u32 DAT_0034b354;
extern void FUN_0010b8cc();
extern void FUN_00110a78();
extern u8 * FUN_001fea10();

void FUN_002a69d0(int param_1,int param_2)
{
  u32 uVar1;
  
  FUN_0010b8cc(*(u32 *)(param_1 + 0x178),param_2,0);
  if (DAT_0034b354 != 0) {
    uVar1 = (unsigned int)(FUN_001fea10(0x12,0x31,*(u32 *)(&DAT_00300af4 + param_2 * 4)));
    FUN_00110a78(DAT_0034b354,uVar1,0);
  }
}
