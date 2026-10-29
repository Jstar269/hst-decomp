/* HSTMATCH module=EBOOT.BIN start=0x0022c94c end=0x0022c988 symbol=FUN_0022c94c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/entry_flags.h"

extern u32 DAT_003415a8;  /* address of the global system block */

/* Sets flags B and C of the flag byte at `index`. */
void FUN_0022c94c(int index)
{
  int addr;
  
  addr = index + 0x8d00 + DAT_003415a8;
  *(u8 *)(addr + 0x3500) = *(u8 *)(addr + 0x3500) | ENTRY_FLAG_B;
  addr = index + 0x8d00 + DAT_003415a8;
  *(u8 *)(addr + 0x3500) = *(u8 *)(addr + 0x3500) | ENTRY_FLAG_C;
}
