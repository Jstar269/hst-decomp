/* HSTMATCH module=EBOOT.BIN start=0x001c35ec end=0x001c364c symbol=FUN_001c35ec lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed FUN_00226128 as int instead of a byte result; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0034a2e0;
extern void FUN_001cd88c();
extern void FUN_002260e0();
extern u32 FUN_00226118();
extern int FUN_00226128();

void FUN_001c35ec(int param_1)
{
  int iVar1;
  u32 uVar2;
  
  iVar1 = FUN_00226128(DAT_0034a2e0);
  if (iVar1 != 0) {
    uVar2 = FUN_00226118(DAT_0034a2e0);
    *(u32 *)(param_1 + 0xf4) = uVar2;
    FUN_002260e0(DAT_0034a2e0);
    FUN_001cd88c(param_1,0,1);
  }
}
