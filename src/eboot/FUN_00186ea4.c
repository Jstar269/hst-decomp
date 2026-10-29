/* HSTMATCH module=EBOOT.BIN start=0x00186ea4 end=0x00186ee8 symbol=FUN_00186ea4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/slide_screen.h"

/* Sets the flag and derives two offsets from base - step * index; clears the two trailing words. */
void FUN_00186ea4(SlideScreen *self,int first,int second)
{
  self->unk1250 = 1;
  self->unk1240 = self->base - self->step * first;
  self->unk1244 = self->base - self->step * second;
  self->unk124c = 0;
  self->unk1248 = 0;
}
