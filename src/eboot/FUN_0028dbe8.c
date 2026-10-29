/* HSTMATCH module=EBOOT.BIN start=0x0028dbe8 end=0x0028dbf8 symbol=FUN_0028dbe8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Shrinks the vector's size by count elements (no destruction). */
void FUN_0028dbe8(RawVec *vec,int count)
{
  vec->size = vec->size - count;
}
