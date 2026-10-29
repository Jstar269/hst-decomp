/* HSTMATCH module=hstp_trans_main.prx start=0x0029b3e0 end=0x0029b3f4 symbol=FUN_0029b3e0 lang=c99 */
/* Clone of src/eboot/FUN_000b5ed4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/word_pair.h"

/* Copy a two-word record (second word loaded first). */
void FUN_0029b3e0(WordPair *dst,WordPair *src)
{
  u32 second;
  
  second = src->second;
  dst->first = src->first;
  dst->second = second;
}
