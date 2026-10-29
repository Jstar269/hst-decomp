/* HSTMATCH module=EBOOT.BIN start=0x0013cef0 end=0x0013cf00 symbol=FUN_0013cef0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Shrinks the element count by n. */
void FUN_0013cef0(RawVec *vec,int n)
{
  vec->size = vec->size - n;
}
