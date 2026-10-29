/* HSTMATCH module=EBOOT.BIN start=0x0012b470 end=0x0012b568 symbol=FUN_0012b470 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/avatar_obj.h"

extern float DAT_002da9cc;
extern int DAT_0033b4b0[];
extern void FUN_0012ad54(Avatar *,int,int,int,int,int,float);
extern int FUN_0012b568(Avatar *);
extern int FUN_0012b72c(Avatar *,int,int);

/* Starts an animation: the selected entry when FUN_0012b568 gives one, else the current or the default animation. */
void FUN_0012b470(Avatar *self,int step,u32 arg)
{
  int selector = FUN_0012b568(self);
  if (selector < 0) {
    int index = FUN_0012b72c(self,self->unk35c,0);
    int offset = index * 2;
    int base = self->unk354;
    int address = base + offset;
    int current = self->unk334;
    if (current >= 0) {
      FUN_0012ad54(self,current,1,0,1,1,-1.0f);
    } else {
      FUN_0012ad54(self,DAT_0033b4b0[0] + address,1,0,1,1,-1.0f);
    }
  } else {
    selector = selector + step;
    FUN_0012ad54(self,DAT_0033b4b0[selector],1,0,arg,1,DAT_002da9cc);
  }
}
