/* HSTMATCH module=EBOOT.BIN start=0x000ed8c0 end=0x000ed8d0 symbol=FUN_000ed8c0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Drop count elements from the end of the growable array (size only). */
void FUN_000ed8c0(RawVec *vec,int count)
{
  vec->size = vec->size - count;
}
