/* HSTMATCH module=hstp_trans_main.prx start=0x001a3da8 end=0x001a3db4 symbol=FUN_001a3da8 lang=c99 */
/* Clone of src/eboot/FUN_00197458.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/text_draw.h"

/* Set the text cell size. */
void FUN_001a3da8(float width, float height, TextDraw *text)
{
  text->cellW = width;
  text->cellH = height;
}
