/* HSTMATCH module=EBOOT.BIN start=0x00155978 end=0x001559c0 symbol=FUN_00155978 lang=c99 data=0x002dcb3c */
/* Clone of src/eboot/debug_flag_notify_00150cdc.c (hstclone.py tag c46): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dcb3c-0x002dcb4c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: DAT_003402f0 is an unsigned char flag (lbu), not u32; exact match verified; names and types await human review. */
#include "hst/types.h"

extern unsigned char DAT_003402f0;
extern u32 DAT_0034a114;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_001cd6e8();

u32 FUN_00155978(u32 param_1,u32 param_2)
{
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(param_2);
    FUN_0014fd94("ReloadSelectPc\n");
  }
  FUN_001cd6e8(DAT_0034a114);
  return 0;
}
