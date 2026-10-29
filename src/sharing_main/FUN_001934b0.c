/* HSTMATCH module=hstp_trans_main.prx start=0x001934b0 end=0x001934c8 symbol=FUN_001934b0 lang=c99 */
/* Clone of src/eboot/FUN_00186d64.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/slide_screen.h"

extern void FUN_00111b58();

/* Calls FUN_00111b58 on the object at 0x285c with an offset of (a - b) * 4 added to `base`. */
void FUN_001934b0(SlideScreen *self,int base,int a,int b)
{
  FUN_00111b58(self->unk285c,base + (a - b) * 4,0);
}
