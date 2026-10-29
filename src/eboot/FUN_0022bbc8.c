/* HSTMATCH module=EBOOT.BIN start=0x0022bbc8 end=0x0022bc14 symbol=FUN_0022bbc8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0022b02c();

/* Set entries 0, 2 and 0xd of the object to 0. */
void FUN_0022bbc8(u32 obj)
{
  FUN_0022b02c(obj,0,0);
  FUN_0022b02c(obj,2,0);
  FUN_0022b02c(obj,0xd,0);
}
