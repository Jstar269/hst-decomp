/* HSTMATCH module=EBOOT.BIN start=0x0017d59c end=0x0017d728 symbol=FUN_0017d59c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: flag local is unsigned char (lbu) and the conditional param_2 reassignment is a ternary; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_mgr.h"

extern void FUN_000943d0();
extern void FUN_0017c39c();
extern void FUN_0017c6d4();
extern void FUN_001fe0f4();
extern int FUN_001fe244();
extern int FUN_001fe584();
extern void FUN_001fe7b8();

void FUN_0017d59c(SlotMgr *self,int *vals,u32 arg3,int on,int slot, u32 arg6)
{
  int found;
  unsigned char use_table;
  
  use_table = '\0';
  found = FUN_001fe244(self->sub5c,&use_table,slot,arg3,vals,on,arg6);
  if (found != VALUE_UNSET) {
    vals = (use_table != '\0') ? (int)self + found * 0x20 + 100 : vals;
    FUN_001fe584(self->sub1a0,slot,arg3,vals,on);
    FUN_001fe7b8(self->sub1a0);
    if (on == 0) {
      self->unk19c = 0;
      self->unk2e0 = 0;
      FUN_001fe0f4(0);
      FUN_0017c6d4(self,1);
      FUN_0017c39c(self,1);
    }
    else {
      self->unk19c = 3;
      self->unk2e0 = 3;
      if (vals[5] != VALUE_UNSET) {
        FUN_000943d0(self->entries[slot]->sub,5);
      }
      found = vals[3];
      if (found != VALUE_UNSET) {
        FUN_000943d0(self->entries[slot]->sub,3);
      }
      found = vals[4];
      if (found != VALUE_UNSET) {
        FUN_000943d0(self->entries[slot]->sub,4);
      }
    }
  }
}
