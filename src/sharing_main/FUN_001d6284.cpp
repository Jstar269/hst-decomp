/* HSTMATCH module=hstp_trans_main.prx start=0x001d6284 end=0x001d62ec symbol=FUN_001d6284 lang=c++ */
/* Clone of src/eboot/FUN_001c7df0.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern int * DAT_003e48c0;
extern void FUN_0013936c(...);
extern u32 FUN_001d94ec(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void m(int); };

/* If the global object exists and the lookup succeeds, configures the object and calls its slot 7 with the first result block. */
extern "C" void FUN_001d6284(u32 a,u32 b)
{
  int found;
  u8 blockA [16];
  u8 blockB [16];
  
  if ((DAT_003e48c0 != (int *)0x0) &&
     (found = FUN_001d94ec(a,b,blockA,blockB), found != 0)) {
    FUN_0013936c(DAT_003e48c0,1,0,0);
    ((VC_0 *)(DAT_003e48c0))->m((int)(blockA));
  }
}
