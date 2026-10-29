/* HSTMATCH module=hstp_trans_main.prx start=0x000b9050 end=0x000b9068 symbol=FUN_000b9050 lang=c99 */
/* Clone of src/eboot/FUN_000b5d60.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/word_pair.h"

/* Copy a two-word record; returns dst. */
WordPair * FUN_000b9050(WordPair *dst,WordPair *src)
{
  dst->first = src->first;
  dst->second = src->second;
  return dst;
}
