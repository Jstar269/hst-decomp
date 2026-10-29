/* HSTMATCH module=hstp_trans_main.prx start=0x001929e8 end=0x00192ac4 symbol=FUN_001929e8 lang=c99 */
/* Clone of src/eboot/FUN_0018629c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/slide_screen.h"

extern void FUN_00191248();
extern void FUN_0019192c();
extern void FUN_001934b0();

/* Positions the slide screen: optionally moves the 0x285c object, then queries and applies the layout. */
void FUN_001929e8(SlideScreen *self,u32 mode,u32 base,u32 first,int second, int reposition,u32 arg6,u32 arg7)
{
  u32 out_a;
  u32 out_b;
  
  if (reposition != 0) {
    FUN_001934b0(self,base,first,second);
  }
  out_a = 0;
  out_b = 0;
  FUN_00191248(self,&out_a,&out_b,mode);
  FUN_0019192c(self,mode,base,first,second,arg6,reposition,out_b,arg7);
  self->cursor->unke0 = (float)second;
}
