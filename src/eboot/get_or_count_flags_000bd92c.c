/* HSTMATCH module=EBOOT.BIN start=0x000bd92c end=0x000bd97c symbol=FUN_000bd92c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v3) corrected by hand: made the indexed flag loop and count explicit; exact match verified; names and types await human review. */
#include "hst/types.h"

u8 FUN_000bd92c(int param_1,int param_2)
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
