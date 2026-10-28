/* HSTMATCH module=EBOOT.BIN start=0x0028a328 end=0x0028a3f4 symbol=FUN_0028a328 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a7); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_00309d08;
extern void FUN_00000a00(...);
extern u32 * FUN_0028686c(...);
extern int * FUN_0028c870(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" u32 * FUN_0028a328(u32 *param_1,short param_2)
{
  int *piVar1;
  u32 *puVar2;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00309d08);
    piVar1 = (int *)param_1[0x1e];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[0x1e] = 0;
    }
    piVar1 = (int *)param_1[0x1d];
    if (piVar1 != (int *)0x0) {
      delete ((VC_1 *)(piVar1));
      param_1[0x1d] = 0;
    }
    puVar2 = param_1 + 0x38;
    if ((puVar2 != (u32 *)0x0) && (puVar2 != (u32 *)0x0)) {
      FUN_0028c870(puVar2,0);
    }
    FUN_0028686c(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
