/* HSTMATCH module=EBOOT.BIN start=0x000e8800 end=0x000e8810 symbol=FUN_000e8800 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Shrinks a growable array's element count by n. */
void FUN_000e8800(RawVec *vec,int n)
{
  vec->size = vec->size - n;
}
