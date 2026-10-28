/* HSTMATCH module=EBOOT.BIN start=0x00154dc8 end=0x00154e30 symbol=FUN_00154dc8 lang=c99 data=0x002dca08 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag q1); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dca08-0x002dca22) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u8 DAT_003402f0;
extern u32 DAT_0034a114;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_001cd55c();

u32 FUN_00154dc8(int param_1,u32 param_2)
{
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(param_2);
    FUN_0014fd94("MoveCamera [%d, %d (%d)]\n",*(u32 *)(param_1 + 8),
                 *(u32 *)(param_1 + 0xc),*(u32 *)(param_1 + 0x10));
  }
  FUN_001cd55c(DAT_0034a114,*(u32 *)(param_1 + 8),*(u32 *)(param_1 + 0x10),
               *(u32 *)(param_1 + 0xc));
  return 0;
}
