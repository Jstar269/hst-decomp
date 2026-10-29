/* HSTMATCH module=EBOOT.BIN start=0x0022c484 end=0x0022c4ac symbol=FUN_0022c484 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003415a8;  /* address of the global system block */

/* Returns the magnitude of the field when it is negative, otherwise 0. */
int FUN_0022c484(void)
{
  int result;
  
  if (*(int *)(DAT_003415a8 + 0xd4d0) < 0) {
    result = -*(int *)(DAT_003415a8 + 0xd4d0);
  }
  else {
    result = 0;
  }
  return result;
}
