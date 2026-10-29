/* HSTMATCH module=EBOOT.BIN start=0x00150cdc end=0x00150d24 symbol=FUN_00150cdc lang=c99 data=0x002dc45c */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: DAT_003402f0 is an unsigned char flag (lbu), not undefined4; readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc45c-0x002dc469) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern unsigned char DAT_003402f0; /* script trace flag */
extern u32 DAT_0034a114;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_001cd3d0();

/* Script command "EnableInput": trace it and ask the host to enable input. */
u32 FUN_00150cdc(u32 cmd,u32 ctx)
{
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(ctx);
    FUN_0014fd94("EnalbeInput\n");
  }
  FUN_001cd3d0(DAT_0034a114);
  return 0;
}
