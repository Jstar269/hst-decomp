/* HSTMATCH module=hstp_trans_main.prx start=0x000c0ea8 end=0x000c0ef8 symbol=FUN_000c0ea8 lang=c99 */
/* Clone of src/eboot/get_or_count_flags_000bd92c.c (hstclone.py tag u4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v3) corrected by hand: made the indexed flag loop and count explicit; exact match verified; names and types await human review. */
#include "hst/types.h"

u8 FUN_000c0ea8(int param_1,int param_2)
{
  int count;
  int index;
  u8 result;
  if (param_2 < 0) {
    count = 0;
    index = 0;
    for (; index < 16; index++) {
      if (*(u8 *)(param_1 + index + 0x21c) != 0) count++;
    }
    result = *(int *)(param_1 + 400) == count;
  } else {
    result = *(u8 *)(param_2 + param_1 + 0x21c);
  }
  return result;
}
