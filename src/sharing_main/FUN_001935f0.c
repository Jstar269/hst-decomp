/* HSTMATCH module=hstp_trans_main.prx start=0x001935f0 end=0x00193634 symbol=FUN_001935f0 lang=c99 */
/* Clone of src/eboot/FUN_00186ea4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/slide_screen.h"

/* Sets the flag and derives two offsets from base - step * index; clears the two trailing words. */
void FUN_001935f0(SlideScreen *self,int first,int second)
{
  self->unk1250 = 1;
  self->unk1240 = self->base - self->step * first;
  self->unk1244 = self->base - self->step * second;
  self->unk124c = 0;
  self->unk1248 = 0;
}
