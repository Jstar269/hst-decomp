/* HSTMATCH module=EBOOT.BIN start=0x0026348c end=0x002634c4 symbol=FUN_0026348c lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a5); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u32 DAT_003386c8;
extern u32 FUN_0008d994(...);
extern void FUN_00259cd8(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void m(); };

extern "C" void FUN_0026348c(void)
{
  int *piVar1;
  
  FUN_00259cd8();
  piVar1 = (int *)FUN_0008d994(DAT_003386c8);
  ((VC_0 *)(piVar1))->m();
}
