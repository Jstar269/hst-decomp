/* HSTMATCH module=EBOOT.BIN start=0x00091080 end=0x00091090 symbol=FUN_00091080 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Drop count elements from the end of the vector (size only). */
void FUN_00091080(RawVec *vec,int count)
{
  vec->size = vec->size - count;
}
