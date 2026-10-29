/* HSTMATCH module=EBOOT.BIN start=0x0027b8b4 end=0x0027b8c4 symbol=FUN_0027b8b4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Drop count elements from the end of the vector (size only). */
void FUN_0027b8b4(RawVec *vec,int count)
{
  vec->size = vec->size - count;
}
