/* HSTMATCH module=EBOOT.BIN start=0x001a4824 end=0x001a48a4 symbol=FUN_001a4824 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag q4) corrected by hand: the range check made unsigned; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_0016b110();
extern int FUN_0016b55c();

u32 FUN_001a4824(u32 param_1,int param_2)
{
  int iVar1;
  u8 *pbVar2;
  int iVar3;
  
  iVar1 = FUN_0016b110();
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      if ((iVar3 == param_2) && (pbVar2 = (u8 *)FUN_0016b55c(iVar3), (unsigned int)(*pbVar2 - 4) < 2)) {
        return 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  return 0;
}
