/* HSTMATCH module=EBOOT.BIN start=0x00095d94 end=0x00095da8 symbol=FUN_00095d94 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* Constructor: first byte cleared, second byte set to 0xff (none). */
s8 * FUN_00095d94(s8 *self)
{
  self[0] = 0;
  self[1] = 0xff;
  return self;
}
