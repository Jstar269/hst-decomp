/* HSTMATCH module=EBOOT.BIN start=0x000e97c4 end=0x000e97d4 symbol=FUN_000e97c4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Drop count elements from the end of the vector (size only). */
void FUN_000e97c4(RawVec *vec,int count)
{
  vec->size = vec->size - count;
}
