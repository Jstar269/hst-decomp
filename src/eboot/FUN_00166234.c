/* HSTMATCH module=EBOOT.BIN start=0x00166234 end=0x00166244 symbol=FUN_00166234 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Shrink the used-element count by `count`. */
void FUN_00166234(RawVec *vec,int count)
{
  vec->size = vec->size - count;
}
