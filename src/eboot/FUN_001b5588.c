/* HSTMATCH module=EBOOT.BIN start=0x001b5588 end=0x001b5594 symbol=FUN_001b5588 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0034179c;
extern void FUN_001b4984();

/* Forward the arguments to the method of the object at DAT_0034179c (the first parameter is unused). */
void FUN_001b5588(u32 unused,int arg1,u32 *arg2,int arg3,u32 arg4, u32 arg5,u32 arg6,u32 arg7)
{
  FUN_001b4984((int *)&DAT_0034179c,arg1,arg2,arg3,arg4,arg5,arg6,arg7);
}
