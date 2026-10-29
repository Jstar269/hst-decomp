/* HSTMATCH module=EBOOT.BIN start=0x000c1b0c end=0x000c1b1c symbol=FUN_000c1b0c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Shrinks the used-element count by n. */
void FUN_000c1b0c(RawVec *vec,int n)
{
  vec->size = vec->size - n;
}
