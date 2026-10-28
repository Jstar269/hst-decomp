/* HSTMATCH module=EBOOT.BIN start=0x002345bc end=0x002345f8 symbol=FUN_002345bc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* Shift the 11-word array up by one slot (last word dropped) and store value at the front. */
void FUN_002345bc(u32 *list,u32 value)
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
