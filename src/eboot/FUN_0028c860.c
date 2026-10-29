/* HSTMATCH module=EBOOT.BIN start=0x0028c860 end=0x0028c870 symbol=FUN_0028c860 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Shrinks the element count by n. */
void FUN_0028c860(RawVec *vec,int n)
{
  vec->size = vec->size - n;
}
