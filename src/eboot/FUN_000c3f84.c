/* HSTMATCH module=EBOOT.BIN start=0x000c3f84 end=0x000c3f94 symbol=FUN_000c3f84 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_00022548();

/* Forwards to the matrix-times-vector helper with the vector and matrix operands swapped. */
void FUN_000c3f84(u32 out,u32 vec,u32 mtx)
{
  FUN_00022548(out,mtx,vec);
}
