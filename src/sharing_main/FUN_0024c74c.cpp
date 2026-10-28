/* HSTMATCH module=hstp_trans_main.prx start=0x0024c74c end=0x0024c7a8 symbol=FUN_0024c74c lang=c++ */
/* Clone of src/eboot/FUN_0023c5b4.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_001118ac(...);
extern void FUN_0024d848(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_0024c74c(int param_1,u32 param_2)
{
  ((VC_0 *)(*(int **)(param_1 + 0x11b8)))->m((int)(0));
  FUN_001118ac(*(u32 *)(param_1 + 0x11b8),4,7);
  FUN_0024d848(param_1,param_2);
}
