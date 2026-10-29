/* HSTMATCH module=EBOOT.BIN start=0x0014b88c end=0x0014b89c symbol=FUN_0014b88c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Drop the last `count` elements from the size. */
void FUN_0014b88c(RawVec *vec,int count)
{
  vec->size = vec->size - count;
}
