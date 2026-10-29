/* HSTMATCH module=EBOOT.BIN start=0x001a4824 end=0x001a48a4 symbol=FUN_001a4824 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag q4) corrected by hand: the range check made unsigned; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_0016b110();
extern int FUN_0016b55c();

/* Nonzero when entry `target` exists and its kind byte is 4 or 5. */
u32 FUN_001a4824(u32 unused,int target)
{
  int count;
  u8 *kind;
  int i;
  
  count = FUN_0016b110();
  i = 0;
  if (0 < count) {
    do {
      if ((i == target) && (kind = (u8 *)FUN_0016b55c(i), (unsigned int)(*kind - 4) < 2)) {
        return 1;
      }
      i = i + 1;
    } while (i < count);
  }
  return 0;
}
