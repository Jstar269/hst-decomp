/* HSTMATCH module=EBOOT.BIN start=0x00295cc4 end=0x00295ccc symbol=FUN_00295cc4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/value_range.h"

extern void FUN_00113580(float value,ValueRange *range);

/* Store `value` into the owner's range, clamped to its limits. */
void FUN_00295cc4(float value,RangeOwner *owner)
{
  FUN_00113580(value,owner->range);
}
