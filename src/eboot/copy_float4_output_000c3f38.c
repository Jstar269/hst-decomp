/* HSTMATCH module=EBOOT.BIN start=0x000c3f38 end=0x000c3f84 symbol=FUN_000c3f38 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: used a four-float temporary and float field copies; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vec.h"

extern void FUN_00022518(Float4 *);

/* Takes a vector from FUN_00022518, clears its w word and copies it to out. */
void FUN_000c3f38(Float4 *out)
{
  Float4 tmp;
  FUN_00022518(&tmp);
  *(u32 *)&tmp.w = 0;
  out->x = tmp.x;
  out->y = tmp.y;
  out->z = tmp.z;
  out->w = tmp.w;
}
