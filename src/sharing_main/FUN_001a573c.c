/* HSTMATCH module=hstp_trans_main.prx start=0x001a573c end=0x001a576c symbol=FUN_001a573c lang=c99 */
/* Clone of src/eboot/FUN_00198d38.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
#include "hst/text_draw.h"

#define NAME_SLOTS 4 /* name strings held by the text object */

/* Returns the name string stored in the slot, or 0 for an index outside the slots. */
char * FUN_001a573c(TextDraw *text,int index)
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
