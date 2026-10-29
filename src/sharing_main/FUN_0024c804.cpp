/* HSTMATCH module=hstp_trans_main.prx start=0x0024c804 end=0x0024c860 symbol=FUN_0024c804 lang=c++ */
/* Clone of src/eboot/FUN_0023c66c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/range_screen.h"

extern "C" {
extern void FUN_001118ac(...);
extern void FUN_0024dfa0(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };

/* Calls virtual slot 1 of the range object with 0, gives it the range (0x10,0x10) and continues with the next step. */
extern "C" void FUN_0024c804(RangeScreen *self,unsigned int arg)
{
  ((VC_0 *)self->range_obj)->m(0);
  FUN_001118ac(self->range_obj,0x10,0x10);
  FUN_0024dfa0(self,arg);
}
