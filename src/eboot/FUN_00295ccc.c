/* HSTMATCH module=EBOOT.BIN start=0x00295ccc end=0x00295cdc symbol=FUN_00295ccc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/value_range.h"

/* Set the limits of the owner's clamped value. */
void FUN_00295ccc(float lo,float hi,RangeOwner *owner)
{
  ValueRange *range;
  
  range = owner->range;
  range->lo = lo;
  range->hi = hi;
  return;
}
