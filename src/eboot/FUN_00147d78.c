/* HSTMATCH module=EBOOT.BIN start=0x00147d78 end=0x00147d88 symbol=FUN_00147d78 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Drops count elements from the end of the vector (size only). */
void FUN_00147d78(RawVec *vec, int count)
{
  vec->size -= count;
}
