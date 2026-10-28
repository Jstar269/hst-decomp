/* HSTMATCH module=EBOOT.BIN start=0x001c3b64 end=0x001c3bac symbol=FUN_001c3b64 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a5); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
}
struct VC_0 { virtual ~VC_0(); };

extern "C" void FUN_001c3b64(int param_1)
{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x58);
  if (piVar1 != (int *)0x0) {
    delete ((VC_0 *)(piVar1));
    *(u32 *)(param_1 + 0x58) = 0;
  }
}
