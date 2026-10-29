/* HSTMATCH module=EBOOT.BIN start=0x0018bd64 end=0x0018bd80 symbol=FUN_0018bd64 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/render_target.h"

extern u32 DAT_00310ff8;
extern void FUN_0018b7a0();

void FUN_0018bd64(RenderTarget *self)
{
  self->dirty = 1;
  DAT_00310ff8 = (unsigned int)(FUN_0018b7a0);
}
