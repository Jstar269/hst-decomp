/* HSTMATCH module=EBOOT.BIN start=0x0012ddd0 end=0x0012de6c symbol=FUN_0012ddd0 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a5); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_00308194;
extern u32 DAT_0033b580;
extern void FUN_00000a00(...);
extern int * FUN_00064a08(...);
extern u32 * FUN_0028686c(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" u32 * FUN_0012ddd0(u32 *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00308194);
    piVar1 = (int *)param_1[0x38];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[0x38] = 0;
    }
    DAT_0033b580 = 0;
    FUN_00064a08(param_1 + 0x34,0xffffffff);
    FUN_0028686c(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
