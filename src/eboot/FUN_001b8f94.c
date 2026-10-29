/* HSTMATCH module=EBOOT.BIN start=0x001b8f94 end=0x001b8fa0 symbol=FUN_001b8f94 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0034179c;
extern void FUN_001b3b64();

void FUN_001b8f94(u32 unused,int arg)
{
  FUN_001b3b64((int *)&DAT_0034179c,arg);
}
