/* HSTMATCH module=EBOOT.BIN start=0x0023c610 end=0x0023c66c symbol=FUN_0023c610 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/range_screen.h"

extern "C" {
extern void FUN_0010b6d4(...);
extern void FUN_0023dda4(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };

/* Calls virtual slot 1 of the range object with 0, gives it the range (8,0xf) and continues with the next step. */
extern "C" void FUN_0023c610(RangeScreen *self,unsigned int arg)
{
  ((VC_0 *)self->range_obj)->m(0);
  FUN_0010b6d4(self->range_obj,8,0xf);
  FUN_0023dda4(self,arg);
}
