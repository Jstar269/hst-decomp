/* HSTMATCH module=hstp_trans_main.prx start=0x001c740c end=0x001c744c symbol=FUN_001c740c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: rewrote the inverted short predicate as a guarded do-while; matching idiom: empty less-than arm; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_001c740c(u32 *first, u32 *last, u32 *out)
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
