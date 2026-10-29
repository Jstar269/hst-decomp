/* HSTMATCH module=EBOOT.BIN start=0x00116e2c end=0x00116e3c symbol=FUN_00116e2c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Drop count elements from the end of the vector (size only). */
void FUN_00116e2c(RawVec *vec,int count)
{
  vec->size = vec->size - count;
}
