/* HSTMATCH module=EBOOT.BIN start=0x0023b5c0 end=0x0023b5d0 symbol=FUN_0023b5c0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Drop count elements from the end of the growable array (size only). */
void FUN_0023b5c0(RawVec *vec,int count)
{
  vec->size = vec->size - count;
}
