/* HSTMATCH module=EBOOT.BIN start=0x0015592c end=0x00155978 symbol=FUN_0015592c lang=c99 data=0x002dcb28 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: the debug flag DAT_003402f0 is a byte (lbu), not a word; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dcb28-0x002dcb3a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u8 DAT_003402f0;
extern u32 DAT_0034a114;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_001cd0d8();

u32 FUN_0015592c(u32 param_1,u32 param_2)
{
  if (DAT_003402f0 != 0) {
    FUN_0014d044(param_2);
    FUN_0014fd94("SetGameOverMatch\n");
  }
  FUN_001cd0d8(DAT_0034a114,1);
  return 0;
}
