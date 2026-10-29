/* HSTMATCH module=hstp_trans_main.prx start=0x00274308 end=0x00274340 symbol=FUN_00274308 lang=c++ */
/* Clone of src/eboot/FUN_0026348c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u32 DAT_003e1a08;
extern u32 FUN_0008f170(...);
extern void FUN_0026a188(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void m(); };

/* Run the helper, then call virtual slot 3 on the object returned for the DAT_003e1a08 handle. */
extern "C" void FUN_00274308(void)
{
  VC_0 *target;
  
  FUN_0026a188();
  target = (VC_0 *)FUN_0008f170(DAT_003e1a08);
  target->m();
}
