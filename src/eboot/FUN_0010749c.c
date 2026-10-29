/* HSTMATCH module=EBOOT.BIN start=0x0010749c end=0x001074ac symbol=FUN_0010749c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Shrinks a growable array's element count by n. */
void FUN_0010749c(RawVec *vec,int n)
{
  vec->size = vec->size - n;
}
