/* HSTMATCH module=EBOOT.BIN start=0x000e984c end=0x000e985c symbol=FUN_000e984c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Drop count elements from the end of the vector (size only). */
void FUN_000e984c(RawVec *vec,int count)
{
  vec->size = vec->size - count;
}
