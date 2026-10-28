/* HSTMATCH module=hstp_trans_main.prx start=0x000c803c end=0x000c80c8 symbol=FUN_000c803c lang=c++ */
/* Clone of src/eboot/global_cleanup_000c47a0.cpp (hstclone.py tag u2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a6) corrected by hand: pass the global pointer to its setter and use the deleting virtual destructor; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern int * DAT_003e1e04;
extern void FUN_00000a00(int);
extern u32 FUN_000bd848(int);
extern u32 FUN_000bdad0(int);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" void FUN_000c803c(int param_1)
{
  int iVar1;
  
  if (DAT_003e1e04 != (int *)0x0) {
    FUN_000bdad0((int)DAT_003e1e04);
    FUN_000bd848((int)DAT_003e1e04);
    if (DAT_003e1e04 != (int *)0x0) {
      delete ((VC_0 *)DAT_003e1e04);
      DAT_003e1e04 = (int *)0x0;
    }
  }
  if (*(int *)(param_1 + 0x784) != 0) {
    FUN_00000a00(*(int *)(param_1 + 0x784));
    *(u32 *)(param_1 + 0x784) = 0;
  }
}
