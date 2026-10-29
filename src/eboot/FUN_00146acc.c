/* HSTMATCH module=EBOOT.BIN start=0x00146acc end=0x00146adc symbol=FUN_00146acc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Shrinks the vector's element count by n (no destruction). */
void FUN_00146acc(RawVec *vec,int n)
{
  vec->size = vec->size - n;
}
