/* HSTMATCH module=EBOOT.BIN start=0x0025b028 end=0x0025b050 symbol=FUN_0025b028 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/deque_owner.h"

/* Copy a circular-deque iterator field by field; returns dst. */
CdequeIter * FUN_0025b028(CdequeIter *dst,CdequeIter *src)
{
  dst->ptr = src->ptr;
  dst->beg = src->beg;
  dst->first = src->first;
  dst->end = src->end;
  return dst;
}
