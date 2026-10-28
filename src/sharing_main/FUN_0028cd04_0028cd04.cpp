/* HSTMATCH module=hstp_trans_main.prx start=0x0028cd04 end=0x0028cdb4 symbol=FUN_0028cd04 lang=c++ */
/* Clone of src/eboot/FUN_0027ba20_0027ba20.cpp (hstclone.py tag u5cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a5/v17c) corrected by hand: declared the loop index before the cursor to match saved-register allocation; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_003b2f2c;
extern void FUN_00000a00(...);
extern u32 * FUN_0001ed28(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" u32 * FUN_0028cd04(u32 *param_1,short param_2)
{
  int *piVar1;
  int iVar3;
  u32 *puVar2;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b2f2c);
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
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}

