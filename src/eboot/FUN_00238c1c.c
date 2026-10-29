/* HSTMATCH module=EBOOT.BIN start=0x00238c1c end=0x00238c2c symbol=FUN_00238c1c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Drop count elements from the end of the vector (size only). */
void FUN_00238c1c(RawVec *vec,int count)
{
  vec->size = vec->size - count;
}
