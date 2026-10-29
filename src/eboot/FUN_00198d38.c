/* HSTMATCH module=EBOOT.BIN start=0x00198d38 end=0x00198d68 symbol=FUN_00198d38 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/text_draw.h"

#define NAME_SLOTS 4 /* name strings held by the text object */

/* Returns the name string stored in the slot, or 0 for an index outside the slots. */
char * FUN_00198d38(TextDraw *text,int index)
{
  char *name;
  
  if (index >= 0 && (index < NAME_SLOTS)) {
    name = text->names[index];
  }
  else {
    name = 0;
  }
  return name;
}
