/* HSTMATCH module=EBOOT.BIN start=0x00115000 end=0x00115020 symbol=FUN_00115000 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/sprite_quad.h"

/* Vertical extent: bottom of quad 6 minus top of quad 0. */
int FUN_00115000(PanelQuads *self)
{
  return (int)(short)(self->quads[6]->y1 - self->quads[0]->y0);
}
