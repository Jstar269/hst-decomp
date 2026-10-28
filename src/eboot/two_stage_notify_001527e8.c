/* HSTMATCH module=EBOOT.BIN start=0x001527e8 end=0x00152858 symbol=FUN_001527e8 lang=c99 data=0x002dc68c */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: DAT_003402f0 is an unsigned char flag (lbu), not undefined4; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc68c-0x002dc69c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern unsigned char DAT_003402f0;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_002878cc();

u32 FUN_001527e8(int param_1,int param_2)
{
  if (*(int *)(param_2 + 0xc) != 0) {
    FUN_002878cc(*(int *)(param_2 + 0xc),*(u32 *)(param_1 + 0xc),*(u32 *)(param_1 + 8)
                );
  }
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(param_2);
    FUN_0014fd94("SePlay [%s:%d]\n",*(u32 *)(param_1 + 0xc),
                 *(u32 *)(param_1 + 8));
  }
  return 0;
}
