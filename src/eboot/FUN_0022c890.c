/* HSTMATCH module=EBOOT.BIN start=0x0022c890 end=0x0022c8b4 symbol=FUN_0022c890 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/entry_flags.h"

extern u32 DAT_003415a8;  /* address of the global system block */

/* Sets flag A of the flag byte at `index`. */
void FUN_0022c890(int index)
{
  int addr;
  
  addr = index + 0x8d00 + DAT_003415a8;
  *(u8 *)(addr + 0x3500) = *(u8 *)(addr + 0x3500) | ENTRY_FLAG_A;
}
