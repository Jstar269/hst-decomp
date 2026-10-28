/* HSTMATCH module=hstp_trans_main.prx start=0x0026e43c end=0x0026e494 symbol=FUN_0026e43c lang=c++ */
/* Clone of src/eboot/FUN_0025dd90.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u32 DAT_003e1a00;
extern void FUN_00108aec(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11(); virtual void m(int); };
struct VC_1 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual int m(); };

extern "C" void FUN_0026e43c(int *param_1)
{
  int iVar1;
  
  ((VC_0 *)(DAT_003e1a00))->m((int)(1));
  iVar1 = ((VC_1 *)(param_1))->m();
  if (iVar1 != 0) {
    FUN_00108aec(param_1);
  }
}
