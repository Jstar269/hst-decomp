/* HSTMATCH module=hstp_trans_main.prx start=0x002446bc end=0x002446f8 symbol=FUN_002446bc lang=c99 */
/* Clone of src/eboot/FUN_002345bc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Shift the 11-word array up by one slot (last word dropped) and store value at the front. */
void FUN_002446bc(u32 *list,u32 value)
{
  int remaining;
  u32 *cur;
  
  remaining = 9;
  cur = list + 9;
  do {
    remaining = remaining + -3;
    cur[1] = *cur;
    *cur = cur[-1];
    cur[-1] = cur[-2];
    cur = cur + -3;
  } while (remaining > 0);
  list[1] = *list;
  *list = value;
}
