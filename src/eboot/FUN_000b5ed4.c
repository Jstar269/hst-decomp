/* HSTMATCH module=EBOOT.BIN start=0x000b5ed4 end=0x000b5ee8 symbol=FUN_000b5ed4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/word_pair.h"

/* Copy a two-word record (second word loaded first). */
void FUN_000b5ed4(WordPair *dst,WordPair *src)
{
  u32 second;
  
  second = src->second;
  dst->first = src->first;
  dst->second = second;
}
