/* HSTMATCH module=EBOOT.BIN start=0x0023c66c end=0x0023c6c8 symbol=FUN_0023c66c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/range_screen.h"

extern "C" {
extern void FUN_0010b6d4(...);
extern void FUN_0023de08(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };

/* Calls virtual slot 1 of the range object with 0, gives it the range (0x10,0x10) and continues with the next step. */
extern "C" void FUN_0023c66c(RangeScreen *self,unsigned int arg)
{
  ((VC_0 *)self->range_obj)->m(0);
  FUN_0010b6d4(self->range_obj,0x10,0x10);
  FUN_0023de08(self,arg);
}
