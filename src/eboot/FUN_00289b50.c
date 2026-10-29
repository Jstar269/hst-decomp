/* HSTMATCH module=EBOOT.BIN start=0x00289b50 end=0x00289b68 symbol=FUN_00289b50 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/word_pair.h"

/* Copy a word pair and return the destination. */
WordPair * FUN_00289b50(WordPair *dst,WordPair *src)
{
  dst->first = src->first;
  dst->second = src->second;
  return dst;
}
