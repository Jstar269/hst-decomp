/* HSTMATCH module=EBOOT.BIN start=0x00186d7c end=0x00186ea4 symbol=FUN_00186d7c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: Ghidra's if/else-if chain over mode is a switch (case 0, 1, 2+3, 4 in source order; retail tests 4,3,2,1,0), with the sub-object call repeated per case; readability pass; exact match verified; names and types await human review. */
#include "hst/slide_screen.h"

extern void FUN_00217548(char *, int, int, int);

/* Forwards (a, b, c) to the sub-objects of three panes plus one pane chosen by mode. */
void FUN_00186d7c(SlideScreen *self,int mode,int a,int b,int c)
{
  FUN_00217548(self->pane2878->sub0d0,a,b,c);
  FUN_00217548(self->pane2880->sub0d0,a,b,c);
  FUN_00217548(self->pane28a8->sub0d0,a,b,c);
  switch (mode) {
  case 0: FUN_00217548(self->pane2888->sub0d0,a,b,c); break;
  case 1: FUN_00217548(self->pane2894->sub0d0,a,b,c); break;
  case 2:
  case 3: FUN_00217548(self->pane28a0->sub0d0,a,b,c); break;
  case 4: break;
  }
}
