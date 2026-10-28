/* HSTMATCH module=EBOOT.BIN start=0x0015194c end=0x001519b4 symbol=FUN_0015194c lang=c99 data=0x002dc554 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag q3); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc554-0x002dc568) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u8 DAT_003402f0;
extern u32 DAT_0034a114;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_001cc7d0();

u32 FUN_0015194c(int param_1,u32 param_2)
{
  FUN_001cc7d0(DAT_0034a114,*(u32 *)(param_1 + 8));
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(param_2);
    FUN_0014fd94("Request Event [%s]\n",*(u32 *)(param_1 + 8));
  }
  return 0;
}
