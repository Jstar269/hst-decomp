/* HSTMATCH module=EBOOT.BIN start=0x0022bf94 end=0x0022bfb0 symbol=FUN_0022bf94 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern char *DAT_003415a8;
extern void FUN_001bfdd0();

/* Forward the two arguments to the helper on the sub-object at +0x80 of the global, with mode 4. */
void FUN_0022bf94(u32 a,u32 b)
{
  FUN_001bfdd0(DAT_003415a8 + 0x80,a,b,4);
}
