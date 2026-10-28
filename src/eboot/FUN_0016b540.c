/* HSTMATCH module=EBOOT.BIN start=0x0016b540 end=0x0016b550 symbol=FUN_0016b540 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a3); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00341d0e;

bool FUN_0016b540(void)
{
  return DAT_00341d0e != '\0';
}
