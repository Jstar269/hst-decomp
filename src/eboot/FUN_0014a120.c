/* HSTMATCH module=EBOOT.BIN start=0x0014a120 end=0x0014a130 symbol=FUN_0014a120 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Shrinks a growable array's element count by n. */
void FUN_0014a120(RawVec *vec,int n)
{
  vec->size = vec->size - n;
}
