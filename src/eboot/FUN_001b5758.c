/* HSTMATCH module=EBOOT.BIN start=0x001b5758 end=0x001b5764 symbol=FUN_001b5758 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0034179c;
extern void FUN_001b4c84();

/* Release slot index of the object at DAT_0034179c (the first parameter is unused). */
void FUN_001b5758(u32 unused,int index)
{
  FUN_001b4c84((u32 *)&DAT_0034179c,index);
}
