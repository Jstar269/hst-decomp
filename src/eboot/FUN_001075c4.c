/* HSTMATCH module=EBOOT.BIN start=0x001075c4 end=0x001075d4 symbol=FUN_001075c4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Shrinks a growable array's element count by n. */
void FUN_001075c4(RawVec *vec,int n)
{
  vec->size = vec->size - n;
}
