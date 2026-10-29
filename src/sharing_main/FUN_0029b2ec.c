/* HSTMATCH module=hstp_trans_main.prx start=0x0029b2ec end=0x0029b304 symbol=FUN_0029b2ec lang=c99 */
/* Clone of src/eboot/FUN_000b5d60.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/word_pair.h"

/* Copy a two-word record; returns dst. */
WordPair * FUN_0029b2ec(WordPair *dst,WordPair *src)
{
  dst->first = src->first;
  dst->second = src->second;
  return dst;
}
