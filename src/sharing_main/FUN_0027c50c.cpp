/* HSTMATCH module=hstp_trans_main.prx start=0x0027c50c end=0x0027c5f0 symbol=FUN_0027c50c lang=c++ data=0x003a6d70 */
/* Clone of src/eboot/FUN_0026b590.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (5 strings, 0x003a6d70-0x003a6dca) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/sharing_screen.h"

extern "C" {
extern u8 DAT_003b264c;
extern u8 DAT_003b2e5c;
extern int FUN_00108124(...);
extern u32 * FUN_0010873c(...);
extern int FUN_00109304(...);
extern void FUN_00109a44(...);
extern void FUN_0027c6a0(...);
}
struct SharingVirt { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void m(); };

/* Constructor of the sharing layout pane: loads the layout, looks up its two pages and the key part, then enters state 0. */
extern "C" SharingPane * FUN_0027c50c(SharingPane *self)
{
  int part;
  
  FUN_0010873c();
  self->vtable = &DAT_003b264c;
  self->unk54 = 0;
  self->unk55 = 0;
  self->key = 0;
  self->vtable = &DAT_003b2e5c;
  FUN_00109a44(self,"data/menu/gamesharing/gamehsareing1layout.lay",0);
  part = FUN_00109304(self,"sharing1",0);
  self->page1 = (SharingWidget *)part;
  part = FUN_00109304(self,"sharing2",0);
  self->page2 = (SharingWidget *)part;
  part = FUN_00108124(self->page1,"key040");
  self->key = *(SharingWidget **)(part + 0x20);
  part = FUN_00108124(self->page2,"assign010");
  *(int *)(part + 0x24) = *(int *)(part + 0x28) + 1;
  self->unk68 = 0;
  FUN_0027c6a0(self,0);
  ((SharingVirt *)(self))->m();
  return self;
}
