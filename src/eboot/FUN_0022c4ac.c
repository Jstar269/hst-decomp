/* HSTMATCH module=EBOOT.BIN start=0x0022c4ac end=0x0022c4d8 symbol=FUN_0022c4ac lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003415a8;  /* address of the global system block */

/* Stores a pair of words in the system block. */
void FUN_0022c4ac(u32 first,u32 second)
{
  *(u32 *)(DAT_003415a8 + 0xe020) = first;
  *(u32 *)(DAT_003415a8 + 0xe024) = second;
}
