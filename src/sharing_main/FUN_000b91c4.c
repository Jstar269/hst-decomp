/* HSTMATCH module=hstp_trans_main.prx start=0x000b91c4 end=0x000b91d8 symbol=FUN_000b91c4 lang=c99 */
/* Clone of src/eboot/FUN_000b5ed4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/word_pair.h"

/* Copy a two-word record (second word loaded first). */
void FUN_000b91c4(WordPair *dst,WordPair *src)
{
  u32 second;
  
  second = src->second;
  dst->first = src->first;
  dst->second = second;
}
