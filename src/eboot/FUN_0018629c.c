/* HSTMATCH module=EBOOT.BIN start=0x0018629c end=0x00186378 symbol=FUN_0018629c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p1) corrected by hand: readability pass (names, structs, constants), on a variant refined by hstperm.py random mutation (perm-p1/r00/f0343_0018629c_m05.c); exact match verified; names and types await human review. */
#include "hst/slide_screen.h"

extern void FUN_00184afc();
extern void FUN_001851e0();
extern void FUN_00186d64();

/* Positions the slide screen: optionally moves the 0x285c object, then queries and applies the layout. */
void FUN_0018629c(SlideScreen *self,u32 mode,u32 base,u32 first,int second, int reposition,u32 arg6,u32 arg7)
{
  u32 out_a;
  u32 out_b;
  
  if (reposition != 0) {
    FUN_00186d64(self,base,first,second);
  }
  out_a = 0;
  out_b = 0;
  FUN_00184afc(self,&out_a,&out_b,mode);
  FUN_001851e0(self,mode,base,first,second,arg6,reposition,out_b,arg7);
  self->cursor->unke0 = (float)second;
}
