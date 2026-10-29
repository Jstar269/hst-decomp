/* HSTMATCH module=EBOOT.BIN start=0x000d7d60 end=0x000d7d70 symbol=FUN_000d7d60 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Removes count elements from the vector's size (the elements are not touched). */
void FUN_000d7d60(RawVec *vec,int count)
{
  vec->size = vec->size - count;
}
