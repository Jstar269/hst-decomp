/* HSTMATCH module=EBOOT.BIN start=0x0014fb58 end=0x0014fb68 symbol=FUN_0014fb58 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Shrink the element count by count. */
void FUN_0014fb58(RawVec *vec,int count)
{
  vec->size = vec->size - count;
}
