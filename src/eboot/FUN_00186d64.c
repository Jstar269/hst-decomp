/* HSTMATCH module=EBOOT.BIN start=0x00186d64 end=0x00186d7c symbol=FUN_00186d64 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/slide_screen.h"

extern void FUN_0010b980();

/* Calls FUN_0010b980 on the object at 0x285c with an offset of (a - b) * 4 added to `base`. */
void FUN_00186d64(SlideScreen *self,int base,int a,int b)
{
  FUN_0010b980(self->unk285c,base + (a - b) * 4,0);
}
