/* HSTMATCH module=EBOOT.BIN start=0x0013fb20 end=0x0013fb30 symbol=FUN_0013fb20 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Drops count elements from the end by reducing the element count (no destructors run). */
void FUN_0013fb20(RawVec *vec,int count)
{
  vec->size = vec->size - count;
}
