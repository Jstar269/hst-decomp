/* HSTMATCH module=EBOOT.BIN start=0x00221298 end=0x00221314 symbol=FUN_00221298 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/lay_pane.h"

extern "C" {
extern void FUN_00103628(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };
struct VC_1 { virtual void d0(); virtual void m(int); };
struct VC_2 { virtual void d0(); virtual void m(int); };
struct VC_3 { virtual void d0(); virtual void m(int); };

/* Clear the base state and the flag, then call virtual slot 1 with 1 on four of the pane entries. */
extern "C" void FUN_00221298(PaneA *self)
{
  FUN_00103628(self,0);
  self->unk58 = 0;
  ((VC_0 *)self->ent[0])->m(1);
  ((VC_1 *)self->ent[2])->m(1);
  ((VC_2 *)self->ent[3])->m(1);
  ((VC_3 *)self->ent[4])->m(1);
}
