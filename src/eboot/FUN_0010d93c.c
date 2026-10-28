/* HSTMATCH module=EBOOT.BIN start=0x0010d93c end=0x0010d948 symbol=FUN_0010d93c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00310fc4;
extern void FUN_00042ecc();

void FUN_0010d93c(void)
{
  FUN_00042ecc(DAT_00310fc4);
}
