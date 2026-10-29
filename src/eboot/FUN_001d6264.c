/* HSTMATCH module=EBOOT.BIN start=0x001d6264 end=0x001d6280 symbol=FUN_001d6264 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* Small object: a word at +4 and a word copied from a source at +8. */
typedef struct WordCell { char pad00[4]; u32 unk04; u32 value; } WordCell;

/* Store *src (when given) as the value and clear the word at +4. */
void FUN_001d6264(WordCell *self,u32 *src)
{
  if (src != (u32 *)0x0) {
    self->value = *src;
  }
  self->unk04 = 0;
}
