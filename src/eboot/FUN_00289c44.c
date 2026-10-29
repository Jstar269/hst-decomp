/* HSTMATCH module=EBOOT.BIN start=0x00289c44 end=0x00289c58 symbol=FUN_00289c44 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/word_pair.h"

/* Copy a word pair (the second word is read before the first is stored). */
void FUN_00289c44(WordPair *dst,WordPair *src)
{
  u32 second;
  
  second = src->second;
  dst->first = src->first;
  dst->second = second;
}
