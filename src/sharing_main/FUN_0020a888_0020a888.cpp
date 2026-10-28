/* HSTMATCH module=hstp_trans_main.prx start=0x0020a888 end=0x0020a938 symbol=FUN_0020a888 lang=c++ */
/* Clone of src/eboot/FUN_001fc170_001fc170.cpp (hstclone.py tag u5cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a5/v17c) corrected by hand: declared the loop index before the cursor to match saved-register allocation; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_003b281c;
extern void FUN_00000a00(...);
extern u32 * FUN_001087a8(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" u32 * FUN_0020a888(u32 *param_1,short param_2)
{
  int *piVar1;
  int iVar3;
  u32 *puVar2;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b281c);
    iVar3 = 0;
    puVar2 = param_1;
    do {
      piVar1 = (int *)puVar2[0x20];
      if (piVar1 != (int *)0x0) {
        delete ((VC_0 *)(piVar1));
        puVar2[0x20] = 0;
      }
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar3 < 3);
    FUN_001087a8(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}

