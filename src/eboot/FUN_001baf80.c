/* HSTMATCH module=EBOOT.BIN start=0x001baf80 end=0x001bafac symbol=FUN_001baf80 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

#define TABLE_BASE 0x5c /* start of the byte table inside the object FUN_0019d474 returns */

extern u32 FUN_0019d474();

/* Byte `index` of the table in the singleton object. */
u8 FUN_001baf80(int index)
{
  int singleton;
  
  singleton = FUN_0019d474();
  return *(u8 *)(index + singleton + TABLE_BASE);
}
