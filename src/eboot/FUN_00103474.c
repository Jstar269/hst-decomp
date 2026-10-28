/* HSTMATCH module=EBOOT.BIN start=0x00103474 end=0x00103480 symbol=FUN_00103474 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0033a680;
extern void FUN_0005185c();

void FUN_00103474(void)
{
  FUN_0005185c((int)&DAT_0033a680);
}
