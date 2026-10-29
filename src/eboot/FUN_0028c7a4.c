/* HSTMATCH module=EBOOT.BIN start=0x0028c7a4 end=0x0028c7b4 symbol=FUN_0028c7a4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Shrinks the element count by n. */
void FUN_0028c7a4(RawVec *vec,int n)
{
  vec->size = vec->size - n;
}
