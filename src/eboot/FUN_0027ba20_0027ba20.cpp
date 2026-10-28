/* HSTMATCH module=EBOOT.BIN start=0x0027ba20 end=0x0027bad0 symbol=FUN_0027ba20 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5/v17c) corrected by hand: declared the loop index before the cursor to match saved-register allocation; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_00309c44;
extern void FUN_00000a00(...);
extern u32 * FUN_0001f0f0(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" u32 * FUN_0027ba20(u32 *param_1,short param_2)
{
  int *piVar1;
  int iVar3;
  u32 *puVar2;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00309c44);
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
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}

