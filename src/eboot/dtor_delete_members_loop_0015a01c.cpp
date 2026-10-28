/* HSTMATCH module=EBOOT.BIN start=0x0015a01c end=0x0015a118 symbol=FUN_0015a01c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: loop index declared before the walking pointer (swaps the s-register pair); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_00309070;
extern u32 DAT_003403f8;
extern void FUN_00000a00(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct VC_2 { virtual ~VC_2(); };

extern "C" u32 * FUN_0015a01c(u32 *param_1,short param_2)
{
  int *piVar1;
  int iVar3;
  u32 *puVar2;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00309070);
    DAT_003403f8 = 0;
    piVar1 = (int *)param_1[9];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[9] = 0;
    }
    piVar1 = (int *)param_1[10];
    if (piVar1 != (int *)0x0) {
      delete ((VC_1 *)(piVar1));
      param_1[10] = 0;
    }
    iVar3 = 0;
    puVar2 = param_1;
    do {
      piVar1 = (int *)puVar2[0xd];
      if (piVar1 != (int *)0x0) {
        delete ((VC_2 *)(piVar1));
        puVar2[0xd] = 0;
      }
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar3 < 3);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
