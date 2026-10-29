/* HSTMATCH module=EBOOT.BIN start=0x0026348c end=0x002634c4 symbol=FUN_0026348c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u32 DAT_003386c8;
extern u32 FUN_0008d994(...);
extern void FUN_00259cd8(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void m(); };

/* Run the helper, then call virtual slot 3 on the object returned for the DAT_003386c8 handle. */
extern "C" void FUN_0026348c(void)
{
  VC_0 *target;
  
  FUN_00259cd8();
  target = (VC_0 *)FUN_0008d994(DAT_003386c8);
  target->m();
}
