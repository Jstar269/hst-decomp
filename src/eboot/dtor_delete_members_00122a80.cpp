/* HSTMATCH module=EBOOT.BIN start=0x00122a80 end=0x00122b48 symbol=FUN_00122a80 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: loop index declared before the member pointer (s-register order); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_00308028;
extern void FUN_00000a00(...);
extern u32 * FUN_0001f0f0(...);
extern int FUN_002161c4(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" u32 * FUN_00122a80(u32 *param_1,short param_2)
{
  int iVar3;
  u32 *puVar2;
  int *piVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00308028);
    iVar3 = 0;
    puVar2 = param_1;
    do {
      piVar1 = (int *)puVar2[0xf];
      if (piVar1 != (int *)0x0) {
        delete ((VC_0 *)(piVar1));
        puVar2[0xf] = 0;
      }
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar3 < 3);
    if (param_1[0x15] != 0) {
      FUN_002161c4(param_1[0x15],1);
      param_1[0x15] = 0;
    }
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
