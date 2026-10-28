/* HSTMATCH module=EBOOT.BIN start=0x001cb7d0 end=0x001cb860 symbol=FUN_001cb7d0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003415ac;
extern void FUN_0010b8cc();
extern void FUN_00114168();
extern void FUN_001c2498();
extern void FUN_001cd88c();
extern u8 * FUN_002294f4();

void FUN_001cb7d0(int param_1,u32 param_2)
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x15c);
  *(u8 *)(iVar2 + 0xb0) = 0;
  iVar1 = (int)(FUN_002294f4(iVar2 + 0x34,*(u32 *)(iVar2 + 0x24),param_2,0));
  if (iVar1 != 0) {
    FUN_00114168(DAT_003415ac,1,iVar1,0,0);
    FUN_0010b8cc(**(u32 **)(DAT_003415ac + 0x58),0,0);
    FUN_001cd88c(iVar2,4,1);
    FUN_001c2498(iVar2);
  }
}
