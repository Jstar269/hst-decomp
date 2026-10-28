/* HSTMATCH module=EBOOT.BIN start=0x001526e4 end=0x00152768 symbol=FUN_001526e4 lang=c99 data=0x002dc674 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: DAT_003402f0 is unsigned char (lbu) and the if/else tests iVar1 >= 10000 first; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc674-0x002dc68b) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern unsigned char DAT_003402f0;
extern u32 DAT_0034a114;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_001cd440();
extern void FUN_001cd490();

u32 FUN_001526e4(int param_1,u32 param_2)
{
  int iVar1;
  
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(param_2);
    FUN_0014fd94("ChangeCamera [%d, %d]\n",*(u32 *)(param_1 + 8),
                 *(u32 *)(param_1 + 0xc));
  }
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 >= 10000) {
    FUN_001cd440(DAT_0034a114,iVar1 + -10000,*(u32 *)(param_1 + 0xc));
  }
  else {
    FUN_001cd490(DAT_0034a114,iVar1,*(u32 *)(param_1 + 0xc));
  }
  return 0;
}
