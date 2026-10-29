/* HSTMATCH module=EBOOT.BIN start=0x0028e5e8 end=0x0028e62c symbol=FUN_0028e5e8 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/titleinfo_menu.h"

extern "C" {
extern void FUN_00103628(...);
extern void FUN_0028e62c(...);
}
struct TitleInfoNotify { virtual void d0(); virtual void d1(); virtual void m(int); };

extern "C" void FUN_0028e5e8(TitleInfoHead *self)
{
  FUN_00103628(self,1);
  self->notify->m(0);
  FUN_0028e62c(self);
}
