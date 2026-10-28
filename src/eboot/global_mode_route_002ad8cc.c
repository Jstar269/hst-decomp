/* HSTMATCH module=EBOOT.BIN start=0x002ad8cc end=0x002ad938 symbol=FUN_002ad8cc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: expressed the three accepted values in retail test order with a switch; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0034a678;
extern int FUN_0016bb88();
extern void FUN_002ad758();

void FUN_002ad8cc(void)
{
  u32 uVar1;
  int uVar2;
  
  uVar2 = 0;
  switch (DAT_0034a678) {
  case 0x14:
  case 0x47:
  case 0x48:
    uVar2 = 1;
    break;
  default:
    break;
  }
  uVar1 = FUN_0016bb88();
  FUN_002ad758(uVar2,uVar1,0);
}
