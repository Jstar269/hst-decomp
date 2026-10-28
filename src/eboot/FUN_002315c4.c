/* HSTMATCH module=EBOOT.BIN start=0x002315c4 end=0x00231614 symbol=FUN_002315c4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int * DAT_0034a65c;
extern u8 DAT_0034a678;
extern int FUN_00231280();
extern void FUN_0023466c();

void FUN_002315c4(void)
{
  if ((DAT_0034a65c != (int *)0x0) && (FUN_00231280(DAT_0034a65c), DAT_0034a65c[1] == 1)) {
    FUN_0023466c((int *)&DAT_0034a678);
  }
}
