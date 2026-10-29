/* HSTMATCH module=hstp_trans_main.prx start=0x0011bed8 end=0x0011beec symbol=FUN_0011bed8 lang=c99 */
/* Clone of src/eboot/FUN_001d61ec.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/layout_list.h"

/* Height of a rectangle (bottom - top). */
int FUN_0011bed8(LayoutQuad *quad)
{
  return (int)(short)(quad->bottom - quad->top);
}
