/* HSTMATCH module=EBOOT.BIN start=0x00115020 end=0x00115040 symbol=FUN_00115020 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/sprite_quad.h"

/* Horizontal extent: right edge of quad 2 minus left edge of quad 0. */
int FUN_00115020(PanelQuads *self)
{
  return (int)(short)(self->quads[2]->x1 - self->quads[0]->x0);
}
