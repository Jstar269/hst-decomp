/* HSTMATCH module=EBOOT.BIN start=0x0015184c end=0x001518cc symbol=FUN_0015184c lang=c99 data=0x002dc540 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag q4); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc540-0x002dc554) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u8 DAT_003402f0;
extern u32 DAT_0034a114;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_001c7160();

u32 FUN_0015184c(int param_1,int param_2)
{
  u32 uVar1;
  
  uVar1 = *(u32 *)(*(int *)(param_2 + 0xc) + 0x30);
  FUN_001c7160(DAT_0034a114,uVar1,*(u32 *)(param_1 + 8));
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(param_2);
    FUN_0014fd94("SetMyLavel [%d:%s]\n",uVar1,*(u32 *)(param_1 + 8));
  }
  return 0;
}
