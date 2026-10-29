/* HSTMATCH module=hstp_trans_main.prx start=0x0023080c end=0x00230888 symbol=FUN_0023080c lang=c++ */
/* Clone of src/eboot/FUN_00221298.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/lay_pane.h"

extern "C" {
extern void FUN_00108f54(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };
struct VC_1 { virtual void d0(); virtual void m(int); };
struct VC_2 { virtual void d0(); virtual void m(int); };
struct VC_3 { virtual void d0(); virtual void m(int); };

/* Clear the base state and the flag, then call virtual slot 1 with 1 on four of the pane entries. */
extern "C" void FUN_0023080c(PaneA *self)
{
  FUN_00108f54(self,0);
  self->unk58 = 0;
  ((VC_0 *)self->ent[0])->m(1);
  ((VC_1 *)self->ent[2])->m(1);
  ((VC_2 *)self->ent[3])->m(1);
  ((VC_3 *)self->ent[4])->m(1);
}
