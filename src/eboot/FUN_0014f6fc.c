/* HSTMATCH module=EBOOT.BIN start=0x0014f6fc end=0x0014f70c symbol=FUN_0014f6fc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Shrink the element count by count. */
void FUN_0014f6fc(RawVec *vec,int count)
{
  vec->size = vec->size - count;
}
