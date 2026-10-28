/* HSTMATCH module=EBOOT.BIN start=0x0018b7ac end=0x0018b804 symbol=FUN_0018b7ac lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0034152c;
extern int FUN_00000bcc();
extern u32 * FUN_0018b944();

void FUN_0018b7ac(u32 param_1,u32 param_2)
{
  int iVar1;
  
  if ((DAT_0034152c == 0) && (iVar1 = FUN_00000bcc(0x90), iVar1 != 0)) {
    FUN_0018b944(iVar1,param_1,param_2);
  }
}
