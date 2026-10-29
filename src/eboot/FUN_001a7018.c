/* HSTMATCH module=EBOOT.BIN start=0x001a7018 end=0x001a7028 symbol=FUN_001a7018 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Shrinks the element count by n. */
void FUN_001a7018(RawVec *vec,int n)
{
  vec->size = vec->size - n;
}
