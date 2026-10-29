/* HSTMATCH module=EBOOT.BIN start=0x001d61ec end=0x001d6200 symbol=FUN_001d61ec lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/layout_list.h"

/* Height of a rectangle (bottom - top). */
int FUN_001d61ec(LayoutQuad *quad)
{
  return (int)(short)(quad->bottom - quad->top);
}
