/* HSTMATCH module=hstp_trans_main.prx start=0x002b4498 end=0x002b44d0 symbol=FUN_002b4498 lang=c++ */
/* Clone of src/eboot/FUN_002a4d08.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u32 DAT_003e1a00;
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11(); virtual void m(int); };

extern "C" void FUN_002b4498(int param_1)
{
  if (*(int *)(param_1 + 0x5d0) != 0) {
    ((VC_0 *)(DAT_003e1a00))->m((int)(1));
  }
}
