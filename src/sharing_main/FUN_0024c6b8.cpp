/* HSTMATCH module=hstp_trans_main.prx start=0x0024c6b8 end=0x0024c700 symbol=FUN_0024c6b8 lang=c++ */
/* Clone of src/eboot/FUN_0023c520.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/range_screen.h"

struct VC_0 { virtual void d0(); virtual void m(int); };
struct VC_1 { virtual void d0(); virtual void m(int); };

/* Calls virtual slot 1 with 0 on two member objects. */
extern "C" void FUN_0024c6b8(RangeScreen *self)
{
  ((VC_0 *)self->unk08)->m(0);
  ((VC_1 *)self->unk28)->m(0);
}
