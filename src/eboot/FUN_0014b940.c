/* HSTMATCH module=EBOOT.BIN start=0x0014b940 end=0x0014b950 symbol=FUN_0014b940 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Drop the last `count` elements from the size. */
void FUN_0014b940(RawVec *vec,int count)
{
  vec->size = vec->size - count;
}
