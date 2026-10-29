/* HSTMATCH module=EBOOT.BIN start=0x0026b590 end=0x0026b674 symbol=FUN_0026b590 lang=c++ data=0x002fe0d4 */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. Data: its string literals (5 strings, 0x002fe0d4-0x002fe12e) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/sharing_screen.h"

extern "C" {
extern u8 DAT_00309380;
extern u8 DAT_00309b74;
extern int FUN_001026b8(...);
extern u32 * FUN_00102e38(...);
extern int FUN_001039d8(...);
extern void FUN_00104118(...);
extern void FUN_0026b724(...);
}
struct SharingVirt { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void m(); };

/* Constructor of the sharing layout pane: loads the layout, looks up its two pages and the key part, then enters state 0. */
extern "C" SharingPane * FUN_0026b590(SharingPane *self)
{
  int part;
  
  FUN_00102e38();
  self->vtable = &DAT_00309380;
  self->unk54 = 0;
  self->unk55 = 0;
  self->key = 0;
  self->vtable = &DAT_00309b74;
  FUN_00104118(self,"data/menu/gamesharing/gamehsareing1layout.lay",0);
  part = FUN_001039d8(self,"sharing1",0);
  self->page1 = (SharingWidget *)part;
  part = FUN_001039d8(self,"sharing2",0);
  self->page2 = (SharingWidget *)part;
  part = FUN_001026b8(self->page1,"key040");
  self->key = *(SharingWidget **)(part + 0x20);
  part = FUN_001026b8(self->page2,"assign010");
  *(int *)(part + 0x24) = *(int *)(part + 0x28) + 1;
  self->unk68 = 0;
  FUN_0026b724(self,0);
  ((SharingVirt *)(self))->m();
  return self;
}
