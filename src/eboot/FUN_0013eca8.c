/* HSTMATCH module=EBOOT.BIN start=0x0013eca8 end=0x0013ecb8 symbol=FUN_0013eca8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Shrinks the vector's element count by n (no destruction). */
void FUN_0013eca8(RawVec *vec,int n)
{
  vec->size = vec->size - n;
}
