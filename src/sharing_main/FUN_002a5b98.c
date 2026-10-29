/* HSTMATCH module=hstp_trans_main.prx start=0x002a5b98 end=0x002a5ba8 symbol=FUN_002a5b98 lang=c99 */
/* Clone of src/eboot/FUN_00295ccc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/value_range.h"

/* Set the limits of the owner's clamped value. */
void FUN_002a5b98(float lo,float hi,RangeOwner *owner)
{
  ValueRange *range;
  
  range = owner->range;
  range->lo = lo;
  range->hi = hi;
  return;
}
