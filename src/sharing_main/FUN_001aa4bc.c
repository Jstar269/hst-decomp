/* HSTMATCH module=hstp_trans_main.prx start=0x001aa4bc end=0x001aa4c8 symbol=FUN_001aa4bc lang=c99 */
/* Clone of src/eboot/FUN_0019cf80.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct ResetTarget {
  char pad00[0xc];
  u32 unkc;     /* 0x0c */
  char pad10[0x42];
  u8 unk52;     /* 0x52 */
} ResetTarget;

/* Clear the word at 0x0c and the byte at 0x52. */
void FUN_001aa4bc(ResetTarget *self)
{
  self->unkc = 0;
  self->unk52 = 0;
}
