/* HSTMATCH module=EBOOT.BIN start=0x00091800 end=0x00091810 symbol=FUN_00091800 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Drop count elements from the end of the vector (size only). */
void FUN_00091800(RawVec *vec,int count)
{
  vec->size = vec->size - count;
}
