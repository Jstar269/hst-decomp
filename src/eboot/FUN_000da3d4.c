/* HSTMATCH module=EBOOT.BIN start=0x000da3d4 end=0x000da3e4 symbol=FUN_000da3d4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Drops count elements from the end of the vector (size only). */
void FUN_000da3d4(RawVec *vec, int count)
{
  vec->size -= count;
}
