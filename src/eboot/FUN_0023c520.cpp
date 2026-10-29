/* HSTMATCH module=EBOOT.BIN start=0x0023c520 end=0x0023c568 symbol=FUN_0023c520 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/range_screen.h"

struct VC_0 { virtual void d0(); virtual void m(int); };
struct VC_1 { virtual void d0(); virtual void m(int); };

/* Calls virtual slot 1 with 0 on two member objects. */
extern "C" void FUN_0023c520(RangeScreen *self)
{
  ((VC_0 *)self->unk08)->m(0);
  ((VC_1 *)self->unk28)->m(0);
}
