/* HSTMATCH module=EBOOT.BIN start=0x00150d24 end=0x00150d6c symbol=FUN_00150d24 lang=c99 data=0x002dc46c */
/* Clone of src/eboot/debug_flag_notify_00150cdc.c (hstclone.py tag c46): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc46c-0x002dc47a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: DAT_003402f0 is an unsigned char flag (lbu), not u32; exact match verified; names and types await human review. */
#include "hst/types.h"

extern unsigned char DAT_003402f0;
extern u32 DAT_0034a114;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_001cd3d8();

u32 FUN_00150d24(u32 param_1,u32 param_2)
{
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(param_2);
    FUN_0014fd94("DisableInput\n");
  }
  FUN_001cd3d8(DAT_0034a114);
  return 0;
}
