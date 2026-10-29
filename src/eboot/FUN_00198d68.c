/* HSTMATCH module=EBOOT.BIN start=0x00198d68 end=0x00198de0 symbol=FUN_00198d68 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: expressed range and null checks as ordered early returns; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/text_draw.h"

#define NAME_SLOTS 4    /* name strings held by the text object */
#define NAME_SIZE 8     /* bytes per name slot, including the terminator */

extern u32 * FUN_000149a8();
extern int FUN_00014a40();

/* Copies name into the slot; ignored for an index outside the slots, a null name or one too long for the slot. */
void FUN_00198d68(TextDraw *text,int index,char *name)
{
  u32 length;

  if (index < 0) return;
  if (index >= NAME_SLOTS) return;
  if (name == 0) return;
  length = FUN_00014a40(name);
  if (length >= NAME_SIZE) return;
  FUN_000149a8(text->names[index],name);
}
