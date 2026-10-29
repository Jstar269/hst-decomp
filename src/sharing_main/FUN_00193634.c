/* HSTMATCH module=hstp_trans_main.prx start=0x00193634 end=0x00193664 symbol=FUN_00193634 lang=c99 */
/* Clone of src/eboot/FUN_00186ee8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/slide_screen.h"

extern void FUN_00108558();

/* Clears the flag and moves the pane at 0x28 to x = base - step * index. */
void FUN_00193634(SlideScreen *self,int index)
{
  self->unk1250 = 0;
  self->pos28->x = (float)(self->base - self->step * index);
  FUN_00108558(self->pos28);
}
