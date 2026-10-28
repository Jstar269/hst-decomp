/* HSTMATCH module=EBOOT.BIN start=0x001541b0 end=0x00154208 symbol=FUN_001541b0 lang=c99 data=0x002dc870 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: DAT_003402f0 is an unsigned char flag (lbu); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc870-0x002dc889) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern unsigned char DAT_003402f0;
extern u32 DAT_0034a114;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_001c7df0();

u32 FUN_001541b0(int param_1,u32 param_2)
{
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(param_2);
    FUN_0014fd94("Target Camera[point:%d]\n",*(u32 *)(param_1 + 8));
  }
  FUN_001c7df0(DAT_0034a114,*(u32 *)(param_1 + 8));
  return 0;
}
