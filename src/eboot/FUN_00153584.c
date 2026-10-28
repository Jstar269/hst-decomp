/* HSTMATCH module=EBOOT.BIN start=0x00153584 end=0x001535f0 symbol=FUN_00153584 lang=c99 data=0x002dc760 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag q3); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc760-0x002dc771) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u8 DAT_003402f0;
extern u8 * DAT_0034a114;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_001c7d30();

u32 FUN_00153584(int param_1,u32 param_2)
{
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(param_2);
    FUN_0014fd94("GotoRoom[%d:%d]\n",*(u32 *)(param_1 + 8),
                 *(u32 *)(param_1 + 0xc));
  }
  FUN_001c7d30(DAT_0034a114,*(u32 *)(DAT_0034a114 + 0xcc),*(int *)(param_1 + 8) + -1,
               *(u32 *)(param_1 + 0xc),0);
  return 0;
}
