/* HSTMATCH module=EBOOT.BIN start=0x000c47a0 end=0x000c482c symbol=FUN_000c47a0 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a6) corrected by hand: pass the global pointer to its setter and use the deleting virtual destructor; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern int * DAT_00338ac4;
extern void FUN_00000a00(int);
extern u32 FUN_000ba504(int);
extern u32 FUN_000ba78c(int);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" void FUN_000c47a0(int param_1)
{
  int iVar1;
  
  if (DAT_00338ac4 != (int *)0x0) {
    FUN_000ba78c((int)DAT_00338ac4);
    FUN_000ba504((int)DAT_00338ac4);
    if (DAT_00338ac4 != (int *)0x0) {
      delete ((VC_0 *)DAT_00338ac4);
      DAT_00338ac4 = (int *)0x0;
    }
  }
  if (*(int *)(param_1 + 0x784) != 0) {
    FUN_00000a00(*(int *)(param_1 + 0x784));
    *(u32 *)(param_1 + 0x784) = 0;
  }
}
