/* HSTMATCH module=hstp_trans_main.prx start=0x002a5b90 end=0x002a5b98 symbol=FUN_002a5b90 lang=c99 */
/* Clone of src/eboot/FUN_00295cc4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/value_range.h"

extern void FUN_0011d7f8(float value,ValueRange *range);

/* Store `value` into the owner's range, clamped to its limits. */
void FUN_002a5b90(float value,RangeOwner *owner)
{
  FUN_0011d7f8(value,owner->range);
}
