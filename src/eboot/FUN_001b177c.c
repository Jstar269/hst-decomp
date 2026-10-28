/* HSTMATCH module=EBOOT.BIN start=0x001b177c end=0x001b1810 symbol=FUN_001b177c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002e97fc;
extern u8 DAT_002e9804;
extern u8 DAT_002e9808;
extern u32 * FUN_00014788();
extern u32 * FUN_000149a8();
extern char * FUN_00014b74();
extern int FUN_00014cfc();
extern char * FUN_00014d64();

void FUN_001b177c(u32 param_1)
{
  u8 *puVar1;
  int iVar2;
  u8 auStack_10 [16];
  
  puVar1 = (u8 *)FUN_00014cfc(param_1,0x2e);
  if (puVar1 != (u8 *)0x0) {
    FUN_000149a8(auStack_10,puVar1);
    *puVar1 = 0;
    FUN_00014788(param_1,&DAT_002e97fc);
    FUN_00014788(param_1,auStack_10);
  }
  iVar2 = (int)(FUN_00014d64(param_1,&DAT_002e9804));
  if (iVar2 != 0) {
    FUN_00014b74(iVar2,&DAT_002e9808,3);
  }
}
