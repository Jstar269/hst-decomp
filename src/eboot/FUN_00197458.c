/* HSTMATCH module=EBOOT.BIN start=0x00197458 end=0x00197464 symbol=FUN_00197458 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/text_draw.h"

/* Set the text cell size. */
void FUN_00197458(float width, float height, TextDraw *text)
{
  text->cellW = width;
  text->cellH = height;
}
