/* HSTMATCH module=EBOOT.BIN start=0x001b9720 end=0x001b9760 symbol=FUN_001b9720 lang=c99 */
/* Clone of src/sharing_main/filter_short_pairs_001c740c.c (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: rewrote the inverted short predicate as a guarded do-while; matching idiom: empty less-than arm; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_001b9720(u32 *first, u32 *last, u32 *out)
{
  if (first != last) {
    do {
      short *item = (short *)*first;
      if (item[0] < item[1]) {
      } else {
        *out++ = (unsigned int)item;
      }
      ++first;
    } while (first != last);
  }
  return out;
}
