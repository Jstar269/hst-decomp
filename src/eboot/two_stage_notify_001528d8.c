/* HSTMATCH module=EBOOT.BIN start=0x001528d8 end=0x00152948 symbol=FUN_001528d8 lang=c99 data=0x002dc69c */
/* Clone of src/eboot/two_stage_notify_001527e8.c (hstclone.py tag c46): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc69c-0x002dc6a9) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: DAT_003402f0 is an unsigned char flag (lbu), not u32; exact match verified; names and types await human review. */
#include "hst/types.h"

extern unsigned char DAT_003402f0;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_00287924();

u32 FUN_001528d8(int param_1,int param_2)
{
  if (*(int *)(param_2 + 0xc) != 0) {
    FUN_00287924(*(int *)(param_2 + 0xc),*(u32 *)(param_1 + 0xc),*(u32 *)(param_1 + 8)
                );
  }
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(param_2);
    FUN_0014fd94("SeStop [%s]\n",*(u32 *)(param_1 + 0xc),
                 *(u32 *)(param_1 + 8));
  }
  return 0;
}
