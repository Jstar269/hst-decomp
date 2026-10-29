/* HSTMATCH module=EBOOT.BIN start=0x001669cc end=0x001669dc symbol=FUN_001669cc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Shrink the used-element count by `count`. */
void FUN_001669cc(RawVec *vec,int count)
{
  vec->size = vec->size - count;
}
