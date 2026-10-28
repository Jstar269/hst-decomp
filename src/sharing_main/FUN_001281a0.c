/* HSTMATCH module=hstp_trans_main.prx start=0x001281a0 end=0x00128224 symbol=FUN_001281a0 lang=c99 */
/* Clone of src/eboot/FUN_0011cc1c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00000a00();
extern u32 * FUN_001285cc();
extern void FUN_00129790();
extern void FUN_0012a530();

int FUN_001281a0(int param_1,short param_2)
{
  char auStack_18 [24];
  u8 auStack_30 [24];
  
  if (param_1 != 0) {
    FUN_0012a530(auStack_30,param_1,*(u32 *)(param_1 + 0x14));
    FUN_0012a530(auStack_18,param_1,0);
    FUN_00129790(param_1,auStack_18,auStack_30);
    FUN_001285cc(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
