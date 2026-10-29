/* HSTMATCH module=EBOOT.BIN start=0x001472b8 end=0x001472c8 symbol=FUN_001472b8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Drops count elements from the end of the vector (size only). */
void FUN_001472b8(RawVec *vec, int count)
{
  vec->size -= count;
}
