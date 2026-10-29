/* HSTMATCH module=EBOOT.BIN start=0x00169f08 end=0x00169f24 symbol=FUN_00169f08 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vec.h"

extern u32 FUN_0000c6dc(float param_1,float param_2);

/* Heading from one position to another: atan2 of the x and z differences. */
void FUN_00169f08(Float4 *from,Float4 *to)
{
  FUN_0000c6dc(to->x - from->x,to->z - from->z);
}
