/* HSTMATCH module=EBOOT.BIN start=0x0012b360 end=0x0012b3d4 symbol=FUN_0012b360 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/avatar_obj.h"

extern int DAT_0033b538;
extern void FUN_0012ad54(Avatar *,int,int,int,int,int,float);
extern int FUN_0012b72c(Avatar *,int,int);

/* Plays the animation at index `DAT_0033b538 + offset` (offset 0 when the helper finds none). */
void FUN_0012b360(Avatar *self,int arg)
{
  int index = FUN_0012b72c(self,self->unk35c,4);
  if (index != 0) {
    index = index + self->unk354;
  }
  FUN_0012ad54(self,DAT_0033b538 + index,1,0,arg,1,-1.0f);
}
