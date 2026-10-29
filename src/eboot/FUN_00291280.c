/* HSTMATCH module=EBOOT.BIN start=0x00291280 end=0x00291298 symbol=FUN_00291280 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0034a810;
extern u32 DAT_0034a814;

/* Stores a pair of values (the caller passes the same value twice) in globals; always returns 1. */
u32 FUN_00291280(u32 unused,u32 value_a,u32 value_b)
{
  DAT_0034a810 = value_a;
  DAT_0034a814 = value_b;
  return 1;
}
