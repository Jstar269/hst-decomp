/* HSTMATCH module=EBOOT.BIN start=0x00215c8c end=0x00215c9c symbol=FUN_00215c8c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Shrinks a growable array's element count by n. */
void FUN_00215c8c(RawVec *vec,int n)
{
  vec->size = vec->size - n;
}
