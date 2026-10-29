/* HSTMATCH module=EBOOT.BIN start=0x000b5d60 end=0x000b5d78 symbol=FUN_000b5d60 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/word_pair.h"

/* Copy a two-word record; returns dst. */
WordPair * FUN_000b5d60(WordPair *dst,WordPair *src)
{
  dst->first = src->first;
  dst->second = src->second;
  return dst;
}
