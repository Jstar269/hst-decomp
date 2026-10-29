/* HSTMATCH module=hstp_trans_main.prx start=0x001e4054 end=0x001e4070 symbol=FUN_001e4054 lang=c99 */
/* Clone of src/eboot/FUN_001d6264.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Small object: a word at +4 and a word copied from a source at +8. */
typedef struct WordCell { char pad00[4]; u32 unk04; u32 value; } WordCell;

/* Store *src (when given) as the value and clear the word at +4. */
void FUN_001e4054(WordCell *self,u32 *src)
{
  if (src != (u32 *)0x0) {
    self->value = *src;
  }
  self->unk04 = 0;
}
